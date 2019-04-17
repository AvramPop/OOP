//
// Created by dani on 3/27/19.
//

#ifndef LAB5_TEST_H
#define LAB5_TEST_H


#include "../service/VictimFileService.h"

class Test {
public:
    void test();
private:
    void testAdd();
    void testRemove();
    void testUpdate();
    void testGetFileByName();
    void testFilter();
    Repository<VictimFile>* repository;

    VictimFileService getTestService();
};


#endif //LAB5_TEST_H
