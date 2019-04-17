//
// Created by dani on 4/17/19.
//

#ifndef LAB6_RELOADED_TEST_H
#define LAB6_RELOADED_TEST_H


#include "VictimFile.h"

class Test {
public:
    void test();
private:
//    void testAdd();
//    void testRemove();
//    void testUpdate();
//    void testGetFileByName();
//    void testFilter();
//    VictimFileService getTestService();
    void stringStreamVictimFile(std::ostream& output, VictimFile victimFile);
    void testVictimFile();

    void testVictimRepository();

    void testRepositoryLoading();

    void testRepositoryDumping();

    void testRepositoryAdding();

    void testRepositoryUpdating();

    void testRepositoryDeleting();

    void testRepositorySize();

    void testRepositoryElementAccess();
};


#endif //LAB6_RELOADED_TEST_H
