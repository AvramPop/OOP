#include <iostream>
#include "model/VictimFile.h"
#include "repository/DynamicVector.h"
#include "test/Test.h"
#include "ui/Scanner.h"

int main(){
    Test test;
    test.test();
    DynamicVector<VictimFile> repository;
    VictimFileService victimFileService = VictimFileService(repository);
    Scanner scanner(victimFileService);
    scanner.runConsole();
}
