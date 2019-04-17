//
// Created by dani on 3/14/19.
//

#ifndef SEM2_PLANET_H
#define SEM2_PLANET_H
typedef struct{
    char *name, *type;
    double distanceFromEarth;
} Planet;
char* getName(Planet* planet);
char* getType(Planet* planet);
double distanceFromEarth(Planet* planet);
Planet* createPlanet(char* name, char* type, double distanceFromEarth);
void destroyPlanet(Planet *planet);
Planet* copyPlanet(Planet *planet);
#endif //SEM2_PLANET_H
