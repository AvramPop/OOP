//
// Created by dani on 3/9/19.
//

#ifndef LAB3_FILE_H
#define LAB3_FILE_H
#define FREE(ptr) do{ \
    free((ptr));      \
    (ptr) = NULL;     \
  }while(0)

typedef struct{
    char* stateOfDeterioration;
    char* fileType;
    int archiveCatalogNumber;
    int yearOfCreation;
} File;

File* createFile(int archiveCatalogNumber, char* stateOfDeterioration, char* fileType, int yearOfCreation);
void destroyFile(File* file);
File* copyFile(File* file);
void toString(File* file, char* string);
void toPlainString(File* file, char* string);

#endif //LAB3_FILE_H
