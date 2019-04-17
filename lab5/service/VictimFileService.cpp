//
// Created by dani on 3/27/19.
//

#include <iostream>
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

vector<VictimFile> VictimFileService::getList(){
    vector<VictimFile> temporaryBuffer;
    VictimFile temporaryVictimFile;
    for(int i = 0; i < repository.getSize(); ++i){
        temporaryVictimFile = repository.at(i);
        temporaryBuffer.push_back(temporaryVictimFile);
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
            if(repository.at(i).getName() == name){
                return repository.at(i);
            }
        }
    }
    throw exception();
}


vector<VictimFile> VictimFileService::getVectorOfFilesWithOriginAndLowerAge(string& origin, int& age){
    vector<VictimFile> temporary;
    vector<VictimFile> temporaryVictimFileListComplete = getList();
    copy_if(temporaryVictimFileListComplete.begin(), temporaryVictimFileListComplete.end(), std::back_inserter(temporary),
            [origin, age](VictimFile victimFile)->bool{return victimFile.getPlaceOfOrigin() == origin && victimFile.getAge() < age;} );
    return temporary;
}
