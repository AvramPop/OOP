//
// Created by dani on 3/15/19.
//

#include "Vector.h"

#ifndef LAB3_FLIESERVICE_H
#define LAB3_FLIESERVICE_H
void addFile(Vector* fileRepository, File* file);
void updateFile(Vector* fileRepository, File* updatedFile);
void removeFile(Vector* fileRepository, int archiveCatalogNumber);
bool hasFileWithCatalogNumber(Vector* fileRepository, int archiveCatalogNumber);
Vector* getVectorOfType(Vector *fileRepository, char *type);
#endif //LAB3_FLIESERVICE_H
