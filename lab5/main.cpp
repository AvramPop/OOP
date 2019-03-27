#include <iostream>
#include "VictimFile.h"
#include "DynamicVector.h"
#include "Test.h"
#include "Scanner.h"

int main(){
    VictimFileService victimFileService;
    Test test;
    test.test();
    Scanner scanner;
    scanner.runConsole(victimFileService);
}
