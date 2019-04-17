//
// Created by dani on 3/14/19.
//

#include <string.h>
#include <stdlib.h>
#include "Planet.h"

char* getName(Planet* planet){
    return planet->name;
}
char* getType(Planet* planet){
    return planet->type;
}
double distanceFromEarth(Planet* planet){
    return planet->distanceFromEarth;
}

Planet *createPlanet(char *name, char *type, double distanceFromEarth){
    Planet* planet = (Planet*) malloc(sizeof(Planet));
    planet->name = (char*) malloc(sizeof(char) * strlen(name) + 1);
    strcpy(planet->name, name);
    planet->type = (char*) malloc(sizeof(char) * strlen(type) + 1);
    strcpy(planet->type, type);
    planet->distanceFromEarth = distanceFromEarth;
    return planet;
}

void destroyPlanet(Planet *planet){
    if(planet){
        free(planet->name);
        free(planet->type);
        free(planet);
    }
}

Planet *copyPlanet(Planet *planet){
    Planet* tempPlanet = (Planet*) malloc(sizeof(Planet));
    tempPlanet->name = (char*) malloc(sizeof(char) * strlen(planet->name) + 1);
    strcpy(tempPlanet->name, planet->name);
    tempPlanet->type = (char*) malloc(sizeof(char) * strlen(planet->type) + 1);
    strcpy(tempPlanet->type, planet->type);
    tempPlanet->distanceFromEarth = planet->distanceFromEarth;
    destroyPlanet(planet);
    return tempPlanet;
}
