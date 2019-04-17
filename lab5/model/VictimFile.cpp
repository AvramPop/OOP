//
// Created by dani on 3/27/19.
//

#include <algorithm>
#include "VictimFile.h"

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

VictimFile::VictimFile() : victimName(""), placeOfOrigin(""), age(-1), photograph(""){}

istream& operator>>(istream& inStream, VictimFile& victimFile){
    string ageString;
    string nameString;
    string placeString;
    string photoString;
    getline(inStream, nameString, ',');
    getline(inStream, placeString, ',');
    placeString.erase(placeString.begin());
    getline(inStream, ageString, ',');
    ageString.erase(ageString.begin());
    getline(inStream, photoString);
    photoString.erase(photoString.begin());
    victimFile.victimName = nameString;
    victimFile.placeOfOrigin = placeString;
    if(!ageString.empty() && all_of(ageString.begin(), ageString.end(), ::isdigit)){
        victimFile.age = stoi(ageString);
    } else {
        throw std::exception();
    }
    victimFile.photograph = photoString;
    return inStream;
}

string VictimFile::toFormattedString(){
    string result = victimName + ", " + placeOfOrigin + ", " + std::to_string(age) + ", " + photograph;
    return result;
}

