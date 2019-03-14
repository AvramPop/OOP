//
// Created by dani on 3/14/19.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "File.h"

File newFile(int archiveCatalogNumber, char *stateOfDeterioration, char *fileType, int yearOfCreation){
    File file;
    file.archiveCatalogNumber = archiveCatalogNumber;
    file.yearOfCreation = yearOfCreation;
    strcpy(file.stateOfDeterioration, stateOfDeterioration);
    strcpy(file.fileType, fileType);
    return file;
}

int getArchiveCatalogNumber(File file){
    return file.archiveCatalogNumber;
}

char *getStateOfDeterioration(File file){
    return file.stateOfDeterioration;
}

char *getFileType(File file){
    return file.fileType;
}

int getYearOfCreation(File file){
    return file.yearOfCreation;
}

char *toString(File file){
    char* fileAsString = (char*)malloc(sizeof(char)*1000);
    char temporaryString[100];
    strcpy(fileAsString, "File #");
    sprintf(temporaryString, "%d", file.archiveCatalogNumber);
    strcat(fileAsString, temporaryString);
    strcat(fileAsString, " state:");
    strcat(fileAsString, file.stateOfDeterioration);
    strcat(fileAsString, " type:");
    strcat(fileAsString, file.fileType);
    strcat(fileAsString, " year:");
    sprintf(temporaryString, "%d", file.yearOfCreation);
    strcat(fileAsString, temporaryString);
    strcat(fileAsString, "\n");
    return fileAsString;
}

char *toStringPlain(File file){
    char* fileAsString = (char*)malloc(sizeof(char)*1000);
    char temporaryString[100];
    strcpy(fileAsString, "");
    sprintf(temporaryString, "%d", file.archiveCatalogNumber);
    strcat(fileAsString, temporaryString);
    strcat(fileAsString, " ");
    strcat(fileAsString, file.stateOfDeterioration);
    strcat(fileAsString, " ");
    strcat(fileAsString, file.fileType);
    strcat(fileAsString, " ");
    sprintf(temporaryString, "%d", file.yearOfCreation);
    strcat(fileAsString, temporaryString);
    strcat(fileAsString, "\n");
    return fileAsString;
}