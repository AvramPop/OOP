//
// Created by dani on 3/27/19.
//

#ifndef LAB5_VICTIMFILESERVICE_H
#define LAB5_VICTIMFILESERVICE_H


#include "../model/VictimFile.h"
#include "../repository/DynamicVector.h"
#include "../repository/Repository.h"
#include <vector>

class VictimFileService {
private:
    Repository<VictimFile>* repository;
public:
    VictimFileService(Repository<VictimFile>* repository) : repository{repository} {};
    /**
     * Get repository size.
     */
    int getRepositorySize();
    /**
     * Add victim file to repository.
     */
    void addVictimFile(VictimFile& newVictimFile);
    /**
     * Remove victim file from repository.
     */
    void removeVictimFile(string name);
    /**
     * Get whole list of victim files.
     */
    vector<VictimFile> getList();
    /**
     * Update victim file with name with updatedVictimFile.
     */
    void updateVictimFile(string name, VictimFile& updatedVictimFile);
    /**
     * Get victim file with name.
     */
    VictimFile getVictimFileWithName(string name);
    /**
     * Return a vector consisting in all VictimFiles having given origin and age lower than given age.
     */
    vector<VictimFile> getVectorOfFilesWithOriginAndLowerAge(string& origin, int& age);
};


#endif //LAB5_VICTIMFILESERVICE_H
