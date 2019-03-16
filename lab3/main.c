#include <stdio.h>
#include <string.h>
#include "File.h"
#include "Vector.h"
#include "Console.h"
#include "FlieService.h"

int main(){
    //todo write tests
    Vector* fileRepository = createVector(10, &copyFile, &destroyFile); //todo test resize
    Vector* history = createVector(10, &copyVector, &destroyVector);
    runConsole(fileRepository, history);
    destroyVector(history);
    destroyVector(fileRepository);
    return 0;
}