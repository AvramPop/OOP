//
// Created by dani on 3/27/19.
//

#include <iostream>
#include <assert.h>
#include "Test.h"
#include "VictimFile.h"
#include "DynamicVector.h"
#include "VictimFileService.h"

void Test::test(){
    testAdd();
    testRemove();
    testUpdate();
}

void Test::testAdd() const{
    VictimFileService testService = getTestService();
    DynamicVector<VictimFile> testBuffer = testService.getList();
    assert(testBuffer[0] == VictimFile(""));
    assert(testBuffer[1] == VictimFile("testName1"));
    assert(testBuffer[3] == VictimFile("testNameComplete1"));
}

void Test::testRemove() const{
    VictimFileService testService = getTestService();
    testService.removeVictimFile("testName1");
    testService.removeVictimFile("nameNotExistent");
    DynamicVector<VictimFile> testBuffer = testService.getList();
    assert(testBuffer[0] == VictimFile(""));
    assert(testBuffer[2] == VictimFile("testNameComplete1"));
    assert(testBuffer[3] == VictimFile("testNameComplete2"));
    assert(!testBuffer.containsElement(VictimFile("testName1")));
}

VictimFileService Test::getTestService() const{
    VictimFileService testService;
    VictimFile testFileEmpty;
    VictimFile testFileWithName1("testName1");
    VictimFile testFileWithName2("testName2");
    VictimFile testFileComplete1("testNameComplete1", "placeOfOrigin1", 10, "photo1");
    VictimFile testFileComplete2("testNameComplete2", "placeOfOrigin2", 10, "photo2");
    VictimFile testFileComplete3("testNameComplete3", "placeOfOrigin3", 10, "photo3");
    VictimFile testFileComplete4("testNameComplete4", "placeOfOrigin4", 10, "photo4");
    VictimFile testFileComplete5("testNameComplete5", "placeOfOrigin5", 10, "photo5");
    VictimFile testFileComplete6("testNameComplete6", "placeOfOrigin6", 10, "photo6");
    VictimFile testFileComplete7("testNameComplete7", "placeOfOrigin7", 10, "photo7");
    VictimFile testFileComplete8("testNameComplete8", "placeOfOrigin8", 10, "photo8");
    VictimFile testFileComplete9("testNameComplete9", "placeOfOrigin9", 10, "photo9");
    testService.addVictimFile(testFileEmpty);
    testService.addVictimFile(testFileWithName1);
    testService.addVictimFile(testFileWithName2);
    testService.addVictimFile(testFileComplete1);
    testService.addVictimFile(testFileComplete2);
    testService.addVictimFile(testFileComplete3);
    testService.addVictimFile(testFileComplete4);
    testService.addVictimFile(testFileComplete5);
    testService.addVictimFile(testFileComplete6);
    testService.addVictimFile(testFileComplete7);
    testService.addVictimFile(testFileComplete8);
    testService.addVictimFile(testFileComplete9);
    return testService;
}

void Test::testUpdate() const{
    VictimFileService testService = getTestService();
    DynamicVector<VictimFile> testBuffer = testService.getList();
    assert(testBuffer[3].photograph == "photo1");
    testService.updateVictimFile("testNameComplete1", VictimFile("testNameComplete1", "updatedOrigin2", 200, "updatedPhoto2"));
    DynamicVector<VictimFile> testBuffer2 = testService.getList();
    assert(testBuffer2[3].photograph == "updatedPhoto2");
}
