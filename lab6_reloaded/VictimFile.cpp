//
// Created by dani on 4/17/19.
//

#include <algorithm>
#include "VictimFile.h"
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
    if(!placeString.empty()){
        placeString.erase(placeString.begin());
    }
    getline(inStream, ageString, ',');
    if(!ageString.empty()){
        ageString.erase(ageString.begin());
    }
    getline(inStream, photoString);
    if(!photoString.empty()){
        photoString.erase(photoString.begin());
    }
    victimFile.victimName = nameString;
    victimFile.placeOfOrigin = placeString;
    if(!ageString.empty()){
        if(all_of(ageString.begin(), ageString.end(), ::isdigit)){
            victimFile.age = stoi(ageString);
        } else {
            throw std::exception();
        }
    }
    victimFile.photograph = photoString;
    return inStream;
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