#include <stdio.h>
#include <string.h>
#include "File.h"
#include "Vector.h"
#include "Console.h"
#include "FlieService.h"
#include "Test.h"

int main(){
    test(); //todo don't upload with this!
    Vector* fileRepository = createVector(10, &copyFile, &destroyFile);
    Vector* history = createVector(10, &copyVector, &destroyVector);
    runConsole(fileRepository, history);
    destroyVector(history);
    destroyVector(fileRepository);
    return 0;
}