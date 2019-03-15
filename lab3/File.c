//
// Created by dani on 3/14/19.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "File.h"

void toString(File* file, char* string){
    char temporaryString[100];
    strcpy(string, "File #");
    sprintf(temporaryString, "%d", file->archiveCatalogNumber);
    strcat(string, temporaryString);
    strcat(string, " state:");
    strcat(string, file->stateOfDeterioration);
    strcat(string, " type:");
    strcat(string, file->fileType);
    strcat(string, " year:");
    sprintf(temporaryString, "%d", file->yearOfCreation);
    strcat(string, temporaryString);
    strcat(string, "\n");
}

void toPlainString(File* file, char* string){
    char temporaryString[100];
    strcpy(string, "");
    sprintf(temporaryString, "%d", file->archiveCatalogNumber);
    strcat(string, temporaryString);
    strcat(string, " ");
    strcat(string, file->stateOfDeterioration);
    strcat(string, " ");
    strcat(string, file->fileType);
    strcat(string, " ");
    sprintf(temporaryString, "%d", file->yearOfCreation);
    strcat(string, temporaryString);
    strcat(string, "\n");
}

File* createFile(int archiveCatalogNumber, char* stateOfDeterioration, char* fileType, int yearOfCreation){
    File* file = (File*) malloc(sizeof(File));
    file->stateOfDeterioration = (char*)malloc(sizeof(char) * (strlen(stateOfDeterioration) + 1));
    strcpy(file->stateOfDeterioration, stateOfDeterioration);
    file->fileType = (char*)malloc(sizeof(char) * (strlen(fileType) + 1));
    strcpy(file->fileType, fileType);

    file->archiveCatalogNumber = archiveCatalogNumber;
    file->yearOfCreation = yearOfCreation;

    return file;
}

void destroyFile(File* file){
    if (file == NULL) return;
    FREE(file->stateOfDeterioration);
    FREE(file->fileType);
    FREE(file);
}

File* copyFile(File* file){
    File* fileCopy = (File*) malloc(sizeof(File));
    fileCopy->stateOfDeterioration = (char*) malloc(sizeof(char) * (strlen(file->stateOfDeterioration) + 1));
    strcpy(fileCopy->stateOfDeterioration, file->stateOfDeterioration);
    fileCopy->fileType = (char*) malloc(sizeof(char) * (strlen(file->fileType) + 1));
    strcpy(fileCopy->fileType, file->fileType);
    fileCopy->archiveCatalogNumber = file->archiveCatalogNumber;
    fileCopy->yearOfCreation = file->yearOfCreation;
    return fileCopy;
}
