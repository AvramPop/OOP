//
// Created by dani on 3/9/19.
//

#ifndef LAB3_FILEREPOSITORY_H
#define LAB3_FILEREPOSITORY_H

#include "File.h"
#include <string.h>
#include <stdbool.h>
typedef void* Object;
typedef void(*DestroyFunction)(Object);
typedef Object(*CopyFunction)(Object);

typedef struct{
    Object* buffer;
    int size, capacity;
    DestroyFunction destroyFunction;
    CopyFunction copyFunction;

} Vector;

Vector* createVector(int initialCapacity, CopyFunction copyFunction, DestroyFunction destroyFunction);

void destroyVector(Vector* vector);

void addToVector(Vector* vector, Object objectToAdd);

void removeFromVector(Vector* vector, int index);

void updateAtIndex(Vector* vector, int index, Object newObject);

void resize(Vector* vector);

Vector* copyVector(Vector *vector);

#endif //LAB3_FILEREPOSITORY_H
