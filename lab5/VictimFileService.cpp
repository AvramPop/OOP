//
// Created by dani on 3/27/19.
//

#include "VictimFileService.h"

void VictimFileService::addVictimFile(VictimFile newVictimFile){
    if(!repository.containsElement(newVictimFile)){
        repository.add(newVictimFile);
    }
}

void VictimFileService::removeVictimFile(string name){
    if(repository.containsElement(VictimFile(name))){
        repository.remove(VictimFile(name));
    }
}

DynamicVector<VictimFile> VictimFileService::getList(){
    DynamicVector<VictimFile> temporaryBuffer;
    for(int i = 0; i < getRepositorySize(); ++i){
        temporaryBuffer.add(repository[i]);
    }
    return temporaryBuffer;
}

void VictimFileService::updateVictimFile(string name, VictimFile updatedVictimFile){
    if(repository.containsElement(VictimFile(name))){
        repository.update(updatedVictimFile);
    }
}

int VictimFileService::getRepositorySize(){
    return repository.getSize();
}