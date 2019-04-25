//
// Created by dani on 4/17/19.
//

#ifndef LAB6_RELOADED_VICTIMFILESERVICE_H
#define LAB6_RELOADED_VICTIMFILESERVICE_H


#include "FileRepository.h"
#include "VictimFile.h"
#include <memory>

class VictimFileService {
    friend class Test;

private:
    std::unique_ptr<Repository<VictimFile>> repository;
public:
    VictimFileService(const VictimFileService& victimFileService);
    VictimFileService(unique_ptr<Repository<VictimFile>> repository);
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
    vector<VictimFile> getVectorOfFilesWithOriginAndLowerAge(string origin, int age);
    VictimFileService& operator=(const VictimFileService& victimFileService);

    VictimFileService();
};


#endif //LAB6_RELOADED_VICTIMFILESERVICE_H
