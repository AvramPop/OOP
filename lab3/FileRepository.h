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

/**
 * Generate new file repository.
 */
FileRepository newFileRepository();

/**
 * Add file to given fileRepository
 */
void add(FileRepository *fileRepository, File file);

/**
 * Update file in given repository
 */
void update(FileRepository *fileRepository, File newFile);

/**
 * Remove file with given number.
 */
void removeFile(FileRepository *fileRepository, int archiveCatalogNumber);

/**
 * Return a repo containing only files of type given
 */
FileRepository getListOfType(FileRepository fileRepository, char type[]);

/**
 * Check whether there is a file with given number.
 */
bool hasFileWithCatalogNumber(FileRepository fileRepository, int archiveCatalogNumber);

/**
 * Get index of file with given number.
 */
int indexOfFile(FileRepository *fileRepository, int archiveCatalogNumber);

/**
 * Print content of repository to standard output.
 */
void printRepository(FileRepository fileRepository);

#endif //LAB3_FILEREPOSITORY_H
