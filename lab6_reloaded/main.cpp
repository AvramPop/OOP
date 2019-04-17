#include <iostream>
#include "Test.h"
#include "Scanner.h"

int main(){
    Test test;
    test.test();
    FileRepository<VictimFile> repository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/data.txt");
    VictimFileService service(repository);
   // Scanner scanner(service);
    Scanner scanner;
    scanner.runConsole();
    return 0;
}