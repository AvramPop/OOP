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
//    FileRepository<VictimFile> fileRepository("/home/dani/Desktop/code/faculta/an1/sem2/OOP/lab6_reloaded/testRepositoryData.txt");
//    fileRepository.add(VictimFile("name5 surname5", "origin5", 5, "photo5"));

}

void Test::testRepositoryUpdating(){

}

void Test::testRepositoryDeleting(){

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
