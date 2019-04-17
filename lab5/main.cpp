#include <iostream>
#include <fstream>
#include "model/VictimFile.h"
#include "repository/DynamicVector.h"
#include "test/Test.h"
#include "ui/Scanner.h"
#include "repository/FileRepository.h"

int main(){
    Test test;
    test.test();
    Repository<VictimFile>* repository = new FileRepository<VictimFile>("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab5/repo.txt");
    VictimFileService victimFileService = VictimFileService(repository);
    Scanner scanner(victimFileService);
    scanner.runConsole();
    delete repository;
    return 0;
}
