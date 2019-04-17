#include <stdio.h>
#include "Planet.h"
#include "DynamicVector.h"


int main(){
    printf("Hello, World!\n");
    Planet* planet1 = createPlanet("Pluto", "small", 53125);
    Planet* planet2 = createPlanet("Uranus", "big", 53125);
    DynamicVector* dynamicVector = createVector(1);
    add(dynamicVector, planet1);
    add(dynamicVector, planet2);
    destroyVector(dynamicVector);
    return 0;
}