//
// Created by dani on 3/27/19.
//

#ifndef LAB5_TEST_H
#define LAB5_TEST_H


#include "VictimFileService.h"

class Test {
public:
    void test();
private:
    void testAdd() const;
    void testRemove() const;
    void testUpdate() const;

    VictimFileService getTestService() const;
};


#endif //LAB5_TEST_H
