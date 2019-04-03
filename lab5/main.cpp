#include <iostream>
#include "model/VictimFile.h"
#include "repository/DynamicVector.h"
#include "test/Test.h"
#include "ui/Scanner.h"

int main(){
//    Test test;
//    test.test();
//    DynamicVector<VictimFile> repository;
//    VictimFileService victimFileService = VictimFileService(repository);
//    Scanner scanner(victimFileService);
//    scanner.runConsole();

    DynamicVector<VictimFile> testList;
    VictimFile testFileComplete1("testNameComplete1", "placeOfOrigin1", 10, "photo1");
    VictimFile testFileComplete2("testNameComplete2", "placeOfOrigin2", 10, "photo2");
    VictimFile testFileComplete3("testNameComplete3", "placeOfOrigin3", 10, "photo3");
    testList.add(testFileComplete1);
    testList.add(testFileComplete2);
    testList.add(testFileComplete3);
    int i = 0;

}
