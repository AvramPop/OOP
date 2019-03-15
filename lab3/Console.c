//
// Created by dani on 3/14/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "Console.h"
#include "FlieService.h"

void UIAdd(Vector *repository, char *token);
void UIDelete(Vector *repository, char *token);
void UIUpdate(Vector *repository, char *token);
void UIList(Vector *repository, char *token);
void UIListAll(Vector *repository);
void UIListOfType(Vector *repository, char *token);
void printFileRepository(Vector *repository);

void runConsole(Vector* fileRepository){
    char* command = (char*) malloc(sizeof(char) * 100);
    char* input = (char*) malloc(sizeof(char) * 100);
    char* token;
    bool inputNotExit = true;
    while(inputNotExit){
        scanf(" %[^\n]s", input);
        token = strtok(input, " ");
        strcpy(command, token);
        if(strcmp(command, "add") == 0){
            UIAdd(fileRepository, token);
        } else if(strcmp(command, "delete") == 0){
            UIDelete(fileRepository, token);
        } else if(strcmp(command, "update") == 0){
            UIUpdate(fileRepository, token);
        } else if(strcmp(command, "list") == 0){
            UIList(fileRepository, token);
        } else if(strcmp(input, "exit") == 0){
            inputNotExit = false;
        }
    }
    FREE(command);
    FREE(input);
}

void UIList(Vector *repository, char *token){
    token = strtok(NULL, " ");
    if(token == NULL){
        UIListAll(repository);
    } else {
        UIListOfType(repository, token);
    }
}

void UIListOfType(Vector *repository, char *type){
    Vector* filesOfType = getVectorOfType(repository, type);
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

void UIUpdate(Vector *repository, char *token){
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

    File* fileToAdd = createFile(number, newState, newType, newYear);
    updateFile(repository, fileToAdd);
    destroyFile(fileToAdd);

    FREE(newType);
    FREE(newState);
}

void UIDelete(Vector *repository, char *token){
    int number;
    token = strtok(NULL, " ");
    number = atoi(token);
    removeFile(repository, number);
}

void UIAdd(Vector *repository, char *token){
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
    File* fileToAdd = createFile(newNumber, newState, newType, newYear);
    addFile(repository, fileToAdd);
    destroyFile(fileToAdd);
    FREE(newType);
    FREE(newState);
}


