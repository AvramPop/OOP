//
// Created by dani on 3/14/19.
//

#ifndef SEM2_DYNAMICVECTOR_H
#define SEM2_DYNAMICVECTOR_H

#include "Planet.h"

typedef Planet* TElem;
typedef struct{
    TElem* buffer;
    int size, capacity;
} DynamicVector;
DynamicVector* createVector(int initialCapacity);
void destroyVector(DynamicVector* dynamicVector);
void add(DynamicVector* dynamicVector, TElem tElem);
#endif //SEM2_DYNAMICVECTOR_H
