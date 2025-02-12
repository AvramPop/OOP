
#include "VictimFileService.h"

vector<VictimFile> VictimFileService::getList(){
    vector<VictimFile> temporaryBuffer;
    VictimFile temporaryVictimFile;
    for(VictimFile victimFile : repository->asList()){
        temporaryBuffer.push_back(victimFile);
    }
    return temporaryBuffer;
}

int VictimFileService::getRepositorySize(){
    return repository->getSize();
}

void VictimFileService::addVictimFile(VictimFile& newVictimFile){
    if(!repository->containsElement(newVictimFile)){
        repository->add(newVictimFile);
    }
}

void VictimFileService::removeVictimFile(string name){
    if(repository->containsElement(VictimFile(name))){
        repository->remove(VictimFile(name));
    }
}

void VictimFileService::updateVictimFile(string name, VictimFile& updatedVictimFile){
    if(repository->containsElement(VictimFile(name))){
        repository->update(updatedVictimFile);
    }
}

VictimFile VictimFileService::getVictimFileWithName(string name){
    if(repository->containsElement(VictimFile(name))){
        for(VictimFile victimFile : repository->asList()){
            if(victimFile.getName() == name){
                return victimFile;
            }
        }
    }
    throw exception();
}

vector<VictimFile> VictimFileService::getVectorOfFilesWithOriginAndLowerAge(string origin, int age){
    vector<VictimFile> temporary;
    vector<VictimFile> temporaryVictimFileListComplete = getList();
    copy_if(temporaryVictimFileListComplete.begin(), temporaryVictimFileListComplete.end(), std::back_inserter(temporary),
            [origin, age](VictimFile victimFile)->bool{return victimFile.getPlaceOfOrigin() == origin && victimFile.getAge() < age;} );
    return temporary;
}

VictimFileService &VictimFileService::operator=(const VictimFileService &victimFileService){
    if(this == &victimFileService){
        return *this;
    }
    repository = victimFileService.repository->clone();
    return *this;
}

VictimFileService::VictimFileService(){}

VictimFileService::VictimFileService(unique_ptr<Repository<VictimFile>> repository){
    currentSelected = 0;
    this->repository = std::move(repository);
}

VictimFileService::VictimFileService(const VictimFileService& victimFileService){
    repository = victimFileService.repository->clone();
}
