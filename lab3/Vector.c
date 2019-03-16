//
// Created by dani on 3/9/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "File.h"
#include "Vector.h"

Vector* createVector(int initialCapacity, CopyFunction copyFunction, DestroyFunction destroyFunction){
    Vector* vector = (Vector*) malloc(sizeof(Vector));
    vector->capacity = initialCapacity;
    vector->size = 0;
    vector->buffer = (Object*) malloc(sizeof(Object) * initialCapacity);

    vector->destroyFunction = destroyFunction;
    vector->copyFunction = copyFunction;

    return vector;
}

void destroyVector(Vector* vector){
    if (vector == NULL) return;
    for (int i = 0; i < vector->size; i++){
        vector->destroyFunction(vector->buffer[i]);
    }
    FREE(vector->buffer);
    FREE(vector);
}

void addToVector(Vector* vector, Object objectToAdd){
    if (vector->size == vector->capacity){
        resize(vector);
    }
    vector->buffer[vector->size++] = vector->copyFunction(objectToAdd);
}

void resize(Vector* vector){
    vector->capacity *= 2;
    Object* temporaryObjectBuffer = (Object*) malloc(sizeof(Object) * vector->capacity);
    for (int i = 0; i < vector->size; i++) {
        temporaryObjectBuffer[i] = vector->buffer[i];
    }
    FREE(vector->buffer);
    vector->buffer = temporaryObjectBuffer;
}

Vector* copyVector(Vector *vector){
    Vector* newVector = (Vector*) malloc(sizeof(Vector));
    newVector->capacity = vector->capacity;
    newVector->size = vector->size;
    newVector->buffer = (Object*) malloc(sizeof(Object) * newVector->capacity);

    newVector->destroyFunction = vector->destroyFunction;
    newVector->copyFunction = vector->copyFunction;

    for(int i = 0; i < vector->size; i++){
        newVector->buffer[i] = vector->copyFunction(vector->buffer[i]);
    }

    return newVector;
}

void removeFromVector(Vector *vector, int index){
    if(index < vector->size && index > -1){
        for(int i = index; i < vector->size - 1; i++){
            vector->destroyFunction(vector->buffer[i]);
            vector->buffer[i] = vector->copyFunction(vector->buffer[i + 1]);
        }
        vector->destroyFunction(vector->buffer[vector->size - 1]);
        vector->size--;
    }
}

void updateAtIndex(Vector *vector, int index, Object newObject){
    vector->destroyFunction(vector->buffer[index]);
    vector->buffer[index] = vector->copyFunction(newObject);
}

void removeAllFromIndex(Vector *vector, int index){
    int count = vector->size - index;
    while(count){
        removeFromVector(vector, index);
        count--;
    }
}
