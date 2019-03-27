//
// Created by dani on 3/27/19.
//

#ifndef LAB5_VICTIMFILESERVICE_H
#define LAB5_VICTIMFILESERVICE_H


#include "VictimFile.h"
#include "DynamicVector.h"

class VictimFileService {
private:
    DynamicVector<VictimFile> repository;
public:
    VictimFileService(){};
    int getRepositorySize();
    void addVictimFile(VictimFile newVictimFile);
    void removeVictimFile(string name);
    DynamicVector<VictimFile> getList();
    void updateVictimFile(string name, VictimFile updatedVictimFile);
};


#endif //LAB5_VICTIMFILESERVICE_H
