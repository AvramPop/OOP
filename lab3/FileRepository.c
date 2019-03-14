//
// Created by dani on 3/9/19.
//

#include <stdio.h>
#include "File.h"
#include "FileRepository.h"

void add(FileRepository *fileRepository, File file) {
    if(!hasFileWithCatalogNumber(*fileRepository, file.archiveCatalogNumber)){
        fileRepository->repository[fileRepository->size] = file;
        fileRepository->size++;
    }
}
void update(FileRepository *fileRepository, File newFile) {
    if(hasFileWithCatalogNumber(*fileRepository, newFile.archiveCatalogNumber)){
        fileRepository->repository[indexOfFile(fileRepository, newFile.archiveCatalogNumber)] = newFile;
    }
}
void removeFile(FileRepository *fileRepository, int archiveCatalogNumber) {
    if(hasFileWithCatalogNumber(*fileRepository, archiveCatalogNumber)){
        int i;
        for(i = indexOfFile(fileRepository, archiveCatalogNumber); i < fileRepository->size - 1; i++){
            fileRepository->repository[i] = fileRepository->repository[i + 1];
        }
        fileRepository->size--;
    }
}

FileRepository getListOfType(FileRepository fileRepository, char type[]){
    FileRepository newFileRepository;
    newFileRepository.size = 0;
    int i, indexInTemporaryList = 0;
    for(i = 0; i < fileRepository.size; i++){
        if(strcmp(fileRepository.repository[i].fileType, type) == 0){
            newFileRepository.repository[indexInTemporaryList++] = fileRepository.repository[i];
        }
    }
    newFileRepository.size = indexInTemporaryList;
    return newFileRepository;
}

bool hasFileWithCatalogNumber(FileRepository fileRepository, int archiveCatalogNumber){
    int i;
    for(i = 0; i < fileRepository.size; i++){
        if(fileRepository.repository[i].archiveCatalogNumber == archiveCatalogNumber){
            return true;
        }
    }
    return false;
}

int indexOfFile(FileRepository *fileRepository, int archiveCatalogNumber){
    int i;
    for(i = 0; i < fileRepository->size; i++){
        if(fileRepository->repository[i].archiveCatalogNumber == archiveCatalogNumber){
            return i;
        }
    }
    return -1;
}

FileRepository newFileRepository(){
    FileRepository fileRepository;
    fileRepository.size = 0;
    return fileRepository;
}

void printRepository(FileRepository fileRepository){
    int i;
    for(i = 0; i < fileRepository.size; i++){
        printf(toStringPlain(fileRepository.repository[i]));
    }
}

