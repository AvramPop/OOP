//
// Created by dani on 3/15/19.
//

#include "Vector.h"
#include "FlieService.h"


int indexOfFile(Vector *fileRepository, int archiveCatalogNumber){
    int i;
    for(i = 0; i < fileRepository->size; i++){
        if(((File*)fileRepository->buffer[i])->archiveCatalogNumber == archiveCatalogNumber){
            return i;
        }
    }
    return -1;
}

void addFile(Vector *fileRepository, File *file){
    addToVector(fileRepository, file);
}

void updateFile(Vector *fileRepository, File *updatedFile){
    updateAtIndex(fileRepository, indexOfFile(fileRepository, updatedFile->archiveCatalogNumber), updatedFile);
}

void removeFile(Vector *fileRepository, int archiveCatalogNumber){
    removeFromVector(fileRepository, indexOfFile(fileRepository, archiveCatalogNumber));
}

Vector* getFilesOfType(Vector *fileRepository, char *type){
    Vector* newFileRepository = createVector(fileRepository->size, fileRepository->copyFunction, fileRepository->destroyFunction);
    int i;
    for(i = 0; i < fileRepository->size; i++){
        if(strcmp(((File*)fileRepository->buffer[i])->fileType, type) == 0){
            addToVector(newFileRepository, fileRepository->buffer[i]);
        }
    }
    return newFileRepository;
}

bool hasFileWithCatalogNumber(Vector *fileRepository, int archiveCatalogNumber){
    return indexOfFile(fileRepository, archiveCatalogNumber) != -1;
}

Vector* getFilesBeforeYear(Vector *fileRepository, int year){
    Vector* newFileRepository = createVector(fileRepository->size, fileRepository->copyFunction, fileRepository->destroyFunction);
    int i;
    for(i = 0; i < fileRepository->size; i++){
        if(((File*)fileRepository->buffer[i])->yearOfCreation < year){
            addToVector(newFileRepository, fileRepository->buffer[i]);
        }
    }
    return newFileRepository;
}

void sortByYear(Vector* vector){
    for(int i = 0; i < vector->size - 1; i++){
        for(int j = i + 1; j < vector->size; j++){
            if(((File*)vector->buffer[i])->yearOfCreation > ((File*)vector->buffer[j])->yearOfCreation){
                File* temporaryFile = vector->copyFunction(vector->buffer[i]);
                vector->destroyFunction(vector->buffer[i]);
                vector->buffer[i] = vector->copyFunction(vector->buffer[j]);
                vector->destroyFunction(vector->buffer[j]);
                vector->buffer[j] = vector->copyFunction(temporaryFile);
                destroyFile(temporaryFile);
            }
        }
    }
}

Vector *getFilesBeforeYearSorted(Vector *fileRepository, int year){
    Vector* filesBeforeYearSorted = getFilesBeforeYear(fileRepository, year);
    sortByYear(filesBeforeYearSorted);
    return filesBeforeYearSorted;
}

