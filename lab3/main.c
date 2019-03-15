#include <stdio.h>
#include <string.h>
#include "File.h"
#include "Vector.h"
#include "Console.h"
#include "FlieService.h"

int main(){
    //todo write tests
    Vector* fileRepository = createVector(10, &copyFile, &destroyFile); //todo test resize
    runConsole(fileRepository);
    destroyVector(fileRepository);
    return 0;
}