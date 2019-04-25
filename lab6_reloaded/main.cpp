#include <iostream>
#include "Test.h"
#include "Scanner.h"

int main(){
    Test test;
    test.test();
    unique_ptr<FileRepository<VictimFile>> repository = make_unique<FileRepository<VictimFile>>("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/data.txt");
    unique_ptr<VictimFileService> service = make_unique<VictimFileService>(move(repository));
  //  Scanner scanner(move(service));
    Scanner scanner;
    scanner.runConsole();
    return 0;
}
