//
// Created by dani on 3/14/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "Console.h"
#include "FlieService.h"

bool UIAdd(Vector *repository, char *token);
bool UIDelete(Vector *repository, char *token);
bool UIUpdate(Vector *repository, char *token);
void UIList(Vector *repository, char *token);
void UIListAll(Vector *repository);
void UIListOfType(Vector *repository, char *token);
void UIListYear(Vector *repository, char *token);
void printFileRepository(Vector *repository);

void runConsole(Vector* fileRepository, Vector* repositoryHistory){
    char* command = (char*) malloc(sizeof(char) * 100);
    char* input = (char*) malloc(sizeof(char) * 100);
    char* token;
    addToVector(repositoryHistory, fileRepository);
    int currentIndexInHistory = 0;
    bool inputNotExit = true;
    while(inputNotExit){
        scanf(" %[^\n]s", input);
        token = strtok(input, " ");
        strcpy(command, token);
        Vector* currentVector = repositoryHistory->copyFunction(repositoryHistory->buffer[currentIndexInHistory]);
        if(strcmp(command, "add") == 0){
            if(UIAdd(currentVector, token)){
                removeAllFromIndex(repositoryHistory, currentIndexInHistory + 1);
                addToVector(repositoryHistory, currentVector);
                currentIndexInHistory = repositoryHistory->size - 1;
            }
        } else if(strcmp(command, "delete") == 0){
            if(UIDelete(currentVector, token)){
                removeAllFromIndex(repositoryHistory, currentIndexInHistory + 1);
                addToVector(repositoryHistory, currentVector);
                currentIndexInHistory = repositoryHistory->size - 1;
            }
        } else if(strcmp(command, "update") == 0){
            if(UIUpdate(currentVector, token)){
                removeAllFromIndex(repositoryHistory, currentIndexInHistory + 1);
                addToVector(repositoryHistory, currentVector);
                currentIndexInHistory = repositoryHistory->size - 1;
            }
        } else if(strcmp(command, "list") == 0){
            UIList(currentVector, token);
        } else if(strcmp(command, "undo") == 0){
            if(currentIndexInHistory > 0){
                currentIndexInHistory--;
            }
        } else if(strcmp(command, "redo") == 0){
            if(currentIndexInHistory < repositoryHistory->size - 1){
                currentIndexInHistory++;
            }
        } else if(strcmp(input, "exit") == 0){
            inputNotExit = false;
        }
        destroyVector(currentVector);
    }
    FREE(command);
    FREE(input);
}

void UIList(Vector *repository, char *token){
    token = strtok(NULL, " ");
    if(token == NULL){
        UIListAll(repository);
    } else if(strtol(token, NULL, 10)) {
        UIListYear(repository, token);
    } else {
        UIListOfType(repository, token);
    }
}

void UIListOfType(Vector *repository, char *type){
    Vector* filesOfType = getFilesOfType(repository, type);
    printFileRepository(filesOfType);
    destroyVector(filesOfType);
}

void UIListAll(Vector *repository){
    printFileRepository(repository);
}

void printFileRepository(Vector *repository){
    for(int i = 0; i < repository->size; i++){
        char string[2000];
        toPlainString(repository->buffer[i], string);
        printf(string);
    }
}

bool UIUpdate(Vector *repository, char *token){
    int number, newYear;
    char* newType = (char*) malloc(sizeof(char) * 100);
    char* newState = (char*) malloc(sizeof(char) * 100);

    token = strtok(NULL, " ");
    number = atoi(token);

    token = strtok(NULL, ", ");
    strcpy(newState, token);

    token = strtok(NULL, ", ");
    strcpy(newType, token);

    token = strtok(NULL, ", ");
    newYear = atoi(token);
    if(hasFileWithCatalogNumber(repository, number)){
        File *fileToAdd = createFile(number, newState, newType, newYear);
        updateFile(repository, fileToAdd);
        destroyFile(fileToAdd);
        FREE(newType);
        FREE(newState);
        return true;
    } else{
        FREE(newType);
        FREE(newState);
        return false;
    }


}

bool UIDelete(Vector *repository, char *token){
    int number;
    token = strtok(NULL, " ");
    number = atoi(token);
    if(hasFileWithCatalogNumber(repository, number)){
        removeFile(repository, number);
        return true;
    } else{
        return false;
    }
}

bool UIAdd(Vector *repository, char *token){
    int newNumber, newYear;
    char* newType = (char*) malloc(sizeof(char) * 100);
    char* newState = (char*) malloc(sizeof(char) * 100);

    token = strtok(NULL, " ");
    newNumber = atoi(token);

    token = strtok(NULL, ", ");
    strcpy(newState, token);

    token = strtok(NULL, ", ");
    strcpy(newType, token);

    token = strtok(NULL, ", ");
    newYear = atoi(token);
    if(!hasFileWithCatalogNumber(repository, newNumber)){
        File *fileToAdd = createFile(newNumber, newState, newType, newYear);
        addFile(repository, fileToAdd);
        destroyFile(fileToAdd);
        FREE(newType);
        FREE(newState);
        return true;
    } else{
        FREE(newType);
        FREE(newState);
        return false;
    }
}

void UIListYear(Vector *repository, char *token){
    Vector* filesBeforeYear = getFilesBeforeYearSorted(repository, atoi(token));
    printFileRepository(filesBeforeYear);
    destroyVector(filesBeforeYear);
}


