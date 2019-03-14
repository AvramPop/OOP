//
// Created by dani on 3/9/19.
//

#ifndef LAB3_FILEREPOSITORY_H
#define LAB3_FILEREPOSITORY_H
#include "File.h"
#include <string.h>
#include <stdbool.h>

typedef struct {
    File repository[300];
    int size;
} FileRepository;

FileRepository newFileRepository();
void add(FileRepository *fileRepository, File file);
void update(FileRepository *fileRepository, File newFile);
void removeFile(FileRepository *fileRepository, int archiveCatalogNumber);
FileRepository getListOfType(FileRepository fileRepository, char type[]);
bool hasFileWithCatalogNumber(FileRepository fileRepository, int archiveCatalogNumber);
int indexOfFile(FileRepository *fileRepository, int archiveCatalogNumber);
void printRepository(FileRepository fileRepository);
#endif //LAB3_FILEREPOSITORY_H
