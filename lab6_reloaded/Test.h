//
// Created by dani on 4/17/19.
//

#ifndef LAB6_RELOADED_TEST_H
#define LAB6_RELOADED_TEST_H


#include "VictimFile.h"
#include "VictimFileService.h"

class Test {
public:
    void test();
private:
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
    void resetFileToDefault(string path);
    void testRepositoryContains();
    VictimFileService getTestService();
    void testVictimService();

    void testServiceGetSize();

    void testServiceAddVictimFile();

    void testServiceRemoveVictimFile();

    void testServiceGetList();

    void testServiceUpdateVictimFile();

    void testServiceGetVictimFileWithName();

    void testServiceGetVectorOfFilesWithOriginAndLowerAge();

    void testMode();

    void testCopyRepository();

    void testServiceAssignment();
};


#endif //LAB6_RELOADED_TEST_H
