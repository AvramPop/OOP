//
// Created by dani on 3/15/19.
//

#include "Vector.h"

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

Vector* getVectorOfType(Vector *fileRepository, char *type){
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
