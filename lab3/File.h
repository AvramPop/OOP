//
// Created by dani on 3/9/19.
//

#ifndef LAB3_FILE_H
#define LAB3_FILE_H

typedef struct {
    int archiveCatalogNumber;
    char stateOfDeterioration[30];
    char fileType[30];
    int yearOfCreation;
} File;

File newFile(int archiveCatalogNumber, char *stateOfDeterioration, char *fileType, int yearOfCreation);
int getArchiveCatalogNumber(File file);
char* getStateOfDeterioration(File file);
char* getFileType(File file);
int getYearOfCreation(File file);
char* toString(File file);
char* toStringPlain(File file);

#endif //LAB3_FILE_H
