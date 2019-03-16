//
// Created by dani on 3/16/19.
//

#include <stdio.h>
#include <assert.h>
#include "Vector.h"
#include "FlieService.h"

void testFilesOfType(){
    Vector* vector = createVector(10, &copyFile, &destroyFile);
    File* file1 = createFile(1, "a", "a", 1);
    File* file2 = createFile(2, "b", "b", 1);
    File* file3 = createFile(3, "c", "c", 1);
    addToVector(vector, file1);
    addToVector(vector, file2);
    addToVector(vector, file3);
    Vector* vectorWithType = getFilesOfType(vector, "a");
    assert(hasFileWithCatalogNumber(vectorWithType, 1) == true);
    destroyFile(file1);
    destroyFile(file2);
    destroyFile(file3);
    destroyVector(vector);
    destroyVector(vectorWithType);
}

void testHasFile(){
    Vector* vector = createVector(10, &copyFile, &destroyFile);
    File* file1 = createFile(1, "a", "a", 1);
    File* file2 = createFile(2, "b", "b", 1);
    File* file3 = createFile(3, "c", "c", 1);
    addToVector(vector, file1);
    addToVector(vector, file2);
    addToVector(vector, file3);
    assert(hasFileWithCatalogNumber(vector, 1) == true);
    assert(hasFileWithCatalogNumber(vector, 5) == false);
    destroyFile(file1);
    destroyFile(file2);
    destroyFile(file3);
    destroyVector(vector);
}

void testAdd(){
    Vector* vector = createVector(10, &copyFile, &destroyFile);
    File* file1 = createFile(1, "a", "a", 1);
    File* file2 = createFile(2, "b", "b", 1);
    File* file3 = createFile(3, "c", "c", 1);
    addToVector(vector, file1);
    addToVector(vector, file2);
    addToVector(vector, file3);
    assert(vector->size == 3);
    assert(strcmp(((File*)vector->buffer[0])->fileType, "a") == 0);
    assert(strcmp(((File*)vector->buffer[1])->fileType, "b") == 0);
    destroyFile(file1);
    destroyFile(file2);
    destroyFile(file3);
    destroyVector(vector);
}

void testUpdate(){
    Vector* vector = createVector(10, &copyFile, &destroyFile);
    File* file1 = createFile(1, "a", "a", 1);
    File* file2 = createFile(2, "b", "b", 1);
    File* file3 = createFile(3, "c", "c", 1);
    addToVector(vector, file1);
    addToVector(vector, file2);
    addToVector(vector, file3);
    updateAtIndex(vector, 1, file3);
    assert(vector->size == 3);
    assert(strcmp(((File*)vector->buffer[1])->fileType, "c") == 0);
    destroyFile(file1);
    destroyFile(file2);
    destroyFile(file3);
    destroyVector(vector);
}

void testDelete(){
    Vector* vector = createVector(10, &copyFile, &destroyFile);
    File* file1 = createFile(1, "a", "a", 1);
    File* file2 = createFile(2, "b", "b", 1);
    File* file3 = createFile(3, "c", "c", 1);
    addToVector(vector, file1);
    addToVector(vector, file2);
    addToVector(vector, file3);
    removeFromVector(vector, 1);
    assert(vector->size == 2);
    assert(strcmp(((File*)vector->buffer[1])->fileType, "c") == 0);
    destroyFile(file1);
    destroyFile(file2);
    destroyFile(file3);
    destroyVector(vector);
}

void testFilesBeforeYear(){
    Vector* vector = createVector(10, &copyFile, &destroyFile);
    File* file1 = createFile(1, "a", "a", 1800);
    File* file2 = createFile(2, "b", "b", 2002);
    File* file3 = createFile(3, "c", "c", 1500);
    addToVector(vector, file1);
    addToVector(vector, file2);
    addToVector(vector, file3);
    Vector* vectorWithYear = getFilesBeforeYearSorted(vector, 2000);
    assert(hasFileWithCatalogNumber(vectorWithYear, 1) == true);
    assert(vectorWithYear->size == 2);
    assert(strcmp(((File*)vectorWithYear->buffer[0])->fileType, "c") == 0);
    destroyFile(file1);
    destroyFile(file2);
    destroyFile(file3);
    destroyVector(vector);
    destroyVector(vectorWithYear);
}

void test(){
    testAdd();
    testUpdate();
    testDelete();
    testHasFile();
    testFilesOfType();
    testFilesBeforeYear();
    printf("all tests passed successfully");
}
