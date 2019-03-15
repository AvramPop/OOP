//
// Created by dani on 3/14/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "Console.h"
void UIAdd(FileRepository *fileRepository, char* currentToken){
    int newNumber, newYear;
    char newType[100], newState[100];

    currentToken = strtok(NULL, " ");
    newNumber = atoi(currentToken);

    currentToken = strtok(NULL, ", ");
    strcpy(newState, currentToken);

    currentToken = strtok(NULL, ", ");
    strcpy(newType, currentToken);

    currentToken = strtok(NULL, ", ");
    newYear = atoi(currentToken);

    add(fileRepository, newFile(newNumber, newState, newType, newYear));
}

void UIDelete(FileRepository *fileRepository, char* currentToken){
    int number;
    currentToken = strtok(NULL, " ");
    number = atoi(currentToken);
    removeFile(fileRepository, number);

}

void UIUpdate(FileRepository *fileRepository, char* currentToken){
    int number, newYear;
    char newType[100], newState[100];

    currentToken = strtok(NULL, " ");
    number = atoi(currentToken);

    currentToken = strtok(NULL, ", ");
    strcpy(newState, currentToken);

    currentToken = strtok(NULL, ", ");
    strcpy(newType, currentToken);

    currentToken = strtok(NULL, ", ");
    newYear = atoi(currentToken);

    update(fileRepository, newFile(number, newState, newType, newYear));
}

void UIListAll(FileRepository fileRepository){
    printRepository(fileRepository);
}

void UIListOfType(FileRepository fileRepository, char* type){
    printRepository(getListOfType(fileRepository, type));
}

void UIList(FileRepository fileRepository, char* currentToken){
    currentToken = strtok(NULL, " ");
    if(currentToken == NULL){
        UIListAll(fileRepository);
    } else {
        UIListOfType(fileRepository, currentToken);
    }
}

void runConsole(FileRepository fileRepository){
    char command[100];
    char input[300];
    char* token;
    bool inputNotExit = true;
    while(inputNotExit){
        scanf(" %[^\n]s", input);
        token = strtok(input, " ");
        strcpy(command, token);
        if(strcmp(command, "add") == 0){
            UIAdd(&fileRepository, token);
        } else if(strcmp(command, "delete") == 0){
            UIDelete(&fileRepository, token);
        } else if(strcmp(command, "update") == 0){
            UIUpdate(&fileRepository, token);
        } else if(strcmp(command, "list") == 0){
            UIList(fileRepository, token);
        } else if(strcmp(input, "exit") == 0){
            inputNotExit = false;
        }
        token = NULL;
    }
}

