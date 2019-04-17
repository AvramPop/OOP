#include "ui/Scanner.h"

int main(){
//    Test test;
//    test.test();
  //  Repository<VictimFile>* repository = new FileRepository<VictimFile>("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab5/repo.txt");
    FileRepository<VictimFile> fileRepository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab5/repo.txt");
    VictimFileService victimFileService = VictimFileService(fileRepository);
    Scanner scanner(victimFileService);
    scanner.runConsole();
    return 0;
}
