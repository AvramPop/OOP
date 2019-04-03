//
// Created by dani on 3/27/19.
//

#include "VictimFileService.h"

void VictimFileService::addVictimFile(VictimFile& newVictimFile){
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

void VictimFileService::updateVictimFile(string name, VictimFile& updatedVictimFile){
    if(repository.containsElement(VictimFile(name))){
        repository.update(updatedVictimFile);
    }
}

int VictimFileService::getRepositorySize(){
    return repository.getSize();
}

VictimFile VictimFileService::getVictimFileWithName(string name){
    if(repository.containsElement(VictimFile(name))){
        for(int i = 0; i < repository.getSize(); i++){
            if(repository[i].getName() == name){
                return repository[i];
            }
        }
    }
    throw exception();
}


DynamicVector<VictimFile> VictimFileService::getVectorOfFilesWithOriginAndLowerAge(string origin, int age){
    DynamicVector<VictimFile> temporary;
    for(int i = 0; i < getRepositorySize(); i++){
        if(getList()[i].getPlaceOfOrigin() == origin &&
            getList()[i].getAge() < age){
            temporary.add(getList()[i]);
        }
    }
    return temporary;
}