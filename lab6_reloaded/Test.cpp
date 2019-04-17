//
// Created by dani on 4/17/19.
//

#include "Test.h"
#include "VictimFile.h"
#include "FileRepository.h"
#include <fstream>
#include <assert.h>
#include <iostream>
#include <sstream>

void Test::test(){
    testVictimFile();
    testVictimRepository();
    testVictimService();
}

void Test::testVictimFile(){
    std::ifstream fin("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testVictimFileData.txt");
    VictimFile victimFile1FromText;
    VictimFile victimFile2FromText;
    VictimFile victimFile3FromText;
    fin >> victimFile1FromText;
    assert(victimFile1FromText.getPhotograph() == "photo1");
    assert(victimFile1FromText == VictimFile("name1"));
    fin >> victimFile2FromText;
    assert(victimFile2FromText.getAge() == 2);
    assert(victimFile2FromText.getName() == "name2 surname2");
    assert(victimFile2FromText == VictimFile("name2 surname2"));
    assert(victimFile2FromText != VictimFile("name2"));
    assert(victimFile1FromText.toFormattedString() == "name1, origin1, 1, photo1");
    stringstream stringStream;
    stringStreamVictimFile(stringStream, victimFile1FromText);
    assert(stringStream.str() == "name1 origin1 1 photo1");
    fin >> victimFile3FromText;
    assert(victimFile3FromText == VictimFile("name3 surname3", "origin3 origin3", 3, "photo3 photo3"));
}

void Test::stringStreamVictimFile(std::ostream &output, VictimFile victimFile){
    output << victimFile;
}

void Test::testVictimRepository(){
    testRepositoryLoading();
    testRepositoryDumping();
    testRepositoryAdding();
    testRepositoryUpdating();
    testRepositoryDeleting();
    testRepositorySize();
    testRepositoryElementAccess();
    testRepositoryContains();
}

void Test::testRepositoryLoading(){
    FileRepository<VictimFile> fileRepository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryData.txt");
    vector<VictimFile> testList = fileRepository.asList();
    assert(testList[0] == VictimFile("name1 surname1"));
    assert(testList[3] == VictimFile("name4 surname4"));
    assert(testList[3].getPhotograph() == "photo4");
    assert(testList.size() == 4);
}

void Test::testRepositoryDumping(){
    FileRepository<VictimFile> fileRepository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryDumping.txt");
    fileRepository.dumpBufferToFile();
    fileRepository.buffer.push_back(VictimFile("name1", "origin1", 1, "photo1"));
    fileRepository.buffer.push_back(VictimFile("name2 surname2", "origin2", 2, "photo2"));
    fileRepository.dumpBufferToFile();
    vector<VictimFile> testList = fileRepository.asList();
    assert(testList[0] == VictimFile("name1"));
    assert(testList[1] == VictimFile("name2 surname2"));
    assert(testList[1].getPhotograph() == "photo2");
    assert(testList.size() == 2);
}

void Test::testRepositoryAdding(){
    FileRepository<VictimFile> fileRepository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryData.txt");
    fileRepository.add(VictimFile("name5 surname5", "origin5", 5, "photo5"));
    assert(fileRepository.getSize() == 5);
    vector<VictimFile> testList = fileRepository.asList();
    assert(testList[0] == VictimFile("name1 surname1"));
    assert(testList[4] == VictimFile("name5 surname5"));
    resetFileToDefault("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryData.txt");
}

void Test::testRepositoryUpdating(){
    FileRepository<VictimFile> fileRepository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryData.txt");
    fileRepository.update(VictimFile("name1 surname1", "upOrigin1", 11, "upPhoto1"));
    assert(fileRepository.at(0).photograph == "upPhoto1");
    fileRepository.update(VictimFile("name4 surname4", "upOrigin4", 44, "upPhoto4"));
    assert(fileRepository.at(3).photograph == "upPhoto4");
    resetFileToDefault("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryData.txt");
}

void Test::testRepositoryDeleting(){
    FileRepository<VictimFile> fileRepository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryData.txt");
    fileRepository.remove(VictimFile("name1 surname1"));
    assert(fileRepository.getSize() == 3);
    assert(fileRepository.at(0) == VictimFile("name2 surname2"));
    resetFileToDefault("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryData.txt");
}

void Test::testRepositorySize(){
    FileRepository<VictimFile> fileRepository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryData.txt");
    assert(fileRepository.getSize() == 4);
}

void Test::testRepositoryElementAccess(){
    FileRepository<VictimFile> fileRepository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryData.txt");
    VictimFile searchResult = fileRepository.at(0);
    assert(searchResult == VictimFile("name1 surname1"));
    try{
        fileRepository.at(5);
        assert(false);
    } catch(exception& exception){
        assert(true);
    }
}

void Test::resetFileToDefault(string path){
    FileRepository<VictimFile> fileRepository(path);
    fileRepository.dumpBufferToFile();
    fileRepository.buffer.push_back(VictimFile("name1 surname1", "origin1", 1, "photo1"));
    fileRepository.buffer.push_back(VictimFile("name2 surname2", "origin2", 2, "photo2"));
    fileRepository.buffer.push_back(VictimFile("name3 surname3", "origin3", 3, "photo3"));
    fileRepository.buffer.push_back(VictimFile("name4 surname4", "origin4", 4, "photo4"));
    fileRepository.dumpBufferToFile();
}

void Test::testRepositoryContains(){
    FileRepository<VictimFile> fileRepository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryData.txt");
    assert(fileRepository.containsElement(VictimFile("name1 surname1")));
    assert(!fileRepository.containsElement(VictimFile("a")));
}

void Test::testVictimService(){
    testServiceGetSize();
    testServiceAddVictimFile();
    testServiceRemoveVictimFile();
    testServiceGetList();
    testServiceUpdateVictimFile();
    testServiceGetVictimFileWithName();
    testServiceGetVectorOfFilesWithOriginAndLowerAge();

}

VictimFileService Test::getTestService(){
    FileRepository<VictimFile> repository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testServiceData.txt");
    VictimFileService testService(repository);
    return testService;
}

void Test::testServiceGetSize(){
    VictimFileService testService = getTestService();
    assert(testService.getRepositorySize() == 4);
}

void Test::testServiceAddVictimFile(){
    VictimFileService testService = getTestService();
    vector<VictimFile> testBuffer = testService.getList();
    assert(testBuffer.size() == 4);
    VictimFile newVictimFile("name5 surname5", "origin5", 5, "photo5");
    testService.addVictimFile(newVictimFile);
    testBuffer = testService.getList();
    assert(testBuffer.size() == 5);
    assert(testBuffer[4] == VictimFile("name5 surname5"));
    resetFileToDefault("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testServiceData.txt");
}

void Test::testServiceRemoveVictimFile(){
    VictimFileService testService = getTestService();
    testService.removeVictimFile("name1 surname1");
    testService.removeVictimFile("nameNotExistent");
    vector<VictimFile> testBuffer = testService.getList();
    assert(testBuffer[0] == VictimFile("name2 surname2"));
    assert(testBuffer[1] == VictimFile("name3 surname3"));
    VictimFile testFile("name1 surname1");
    assert(!(find(testBuffer.begin(), testBuffer.end(), testFile) != testBuffer.end()));
    resetFileToDefault("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testServiceData.txt");
}

void Test::testServiceGetList(){
    VictimFileService testService = getTestService();
    vector<VictimFile> testBuffer = testService.getList();
    assert(testBuffer[0] == VictimFile("name1 surname1"));
    assert(testBuffer.size() == 4);
}

void Test::testServiceUpdateVictimFile(){
    VictimFileService testService = getTestService();
    vector<VictimFile> testBuffer = testService.getList();
    assert(testBuffer[0].photograph == "photo1");
    VictimFile updatedFile = VictimFile("name2 surname2", "updatedOrigin2", 200, "updatedPhoto2");
    testService.updateVictimFile("name1 surname1", updatedFile);
    vector<VictimFile> testBuffer2 = testService.getList();
    assert(testBuffer2[1].photograph == "updatedPhoto2");
    resetFileToDefault("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testServiceData.txt");
}

void Test::testServiceGetVictimFileWithName(){
    VictimFileService testService = getTestService();
    assert(testService.getVictimFileWithName("name1 surname1") == VictimFile("name1 surname1"));
    assert(testService.getVictimFileWithName("name2 surname2").getAge() == 2);
    try{
        testService.getVictimFileWithName("wrong name");
        assert(false);
    } catch(exception& exception){
        assert(true);
    }
}

void Test::testServiceGetVectorOfFilesWithOriginAndLowerAge(){
    VictimFileService testService = getTestService();
    vector<VictimFile> filterResult = testService.getVectorOfFilesWithOriginAndLowerAge("origin1", 100);
    assert(filterResult[0] == VictimFile("name1 surname1"));
}

