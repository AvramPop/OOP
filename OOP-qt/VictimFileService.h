#ifndef VICTIMFILESERVICE_H
#define VICTIMFILESERVICE_H




#include "FileRepository.h"
#include "VictimFile.h"
#include <memory>

class VictimFileService {
    friend class Test;

private:
    std::unique_ptr<Repository<VictimFile>> repository;
    vector<VictimFile> transferList;
    int currentSelected;
    std::string transferListLocation;
public:
    VictimFileService(const VictimFileService& victimFileService);
    VictimFileService(unique_ptr<Repository<VictimFile>> repository);
    /**
     * Get repository size.
     */
    void setTransferListLocation(std::string location) {transferListLocation = location;}
    std::string getTransferListLocation(){return transferListLocation;}
    int getCurrentSelected() {return currentSelected;}
    void nextSelected() {currentSelected++; if(currentSelected == transferList.size()) currentSelected = 0;}
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

    void addToTransfer(VictimFile victimFile) {transferList.push_back(victimFile);}
    std::vector<VictimFile> getTransfer() {return transferList;}
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


#endif // VICTIMFILESERVICE_H
