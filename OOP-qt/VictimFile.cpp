
#include <algorithm>
#include "VictimFile.h"
#include "Validator.h"
#include "Exception.h"
#include <fstream>

bool VictimFile::operator==(const VictimFile &rhs) const{
    return victimName == rhs.victimName;
}

bool VictimFile::operator!=(const VictimFile &rhs) const{
    return !(rhs == *this);
}

ostream &operator<<(ostream &outputStream, const VictimFile &file){
    string result = file.victimName + " " + file.placeOfOrigin + " " + std::to_string(file.age) + " " + file.photograph;
    outputStream << result;
    return outputStream;
}

VictimFile::VictimFile(string victimName, string placeOfOrigin, int age, string photograph)
        : victimName(victimName), placeOfOrigin(placeOfOrigin), age(age), photograph(photograph){}

VictimFile::VictimFile(string name) : victimName(name), placeOfOrigin(""), age(-1), photograph(""){}

istream& operator>>(istream& inStream, VictimFile& victimFile){
    string ageString;
    string nameString;
    string placeString;
    string photoString;
    getline(inStream, nameString, ',');
    getline(inStream, placeString, ',');
    try{
        placeString.erase(placeString.begin());
    } catch(exception& exception){
        throw ValidatorException();
    }
    getline(inStream, ageString, ',');
    try{
        ageString.erase(ageString.begin());
    } catch(exception& exception){
        throw ValidatorException();
    }
    getline(inStream, photoString);
    try{
        photoString.erase(photoString.begin());
    } catch(exception& exception){
        throw ValidatorException();
    }
    Validator validator;
    if(validator.validateVictimFile(nameString, placeString, ageString, photoString)){
        victimFile.victimName = nameString;
        victimFile.placeOfOrigin = placeString;
        victimFile.age = stoi(ageString);
        victimFile.photograph = photoString;
        return inStream;
    } else {
        throw ValidatorException();
    }
}

string VictimFile::toFormattedString(){
    string result = victimName + ", " + placeOfOrigin + ", " + std::to_string(age) + ", " + photograph;
    return result;
}

VictimFile::VictimFile(){}

VictimFile& VictimFile::operator=(const VictimFile& victimFile){
    if(this == &victimFile){
        return *this;
    }
    victimName = victimFile.victimName;
    placeOfOrigin = victimFile.placeOfOrigin;
    age = victimFile.age;
    photograph = victimFile.photograph;
    return *this;
}