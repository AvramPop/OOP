//
// Created by dani on 3/27/19.
//

#include "VictimFile.h"

bool VictimFile::operator==(const VictimFile &rhs) const{
    return victimName == rhs.victimName;
}

bool VictimFile::operator!=(const VictimFile &rhs) const{
    return !(rhs == *this);
}

ostream &operator<<(ostream &outputStream, const VictimFile &file){
    outputStream << file.victimName << " " << file.placeOfOrigin << " " << file.age << " " << file.photograph;
    return outputStream;
}

VictimFile::VictimFile(string victimName, string placeOfOrigin, int age, string photograph)
        : victimName(victimName), placeOfOrigin(placeOfOrigin), age(age), photograph(photograph){}

VictimFile::VictimFile(string name) : victimName(name), placeOfOrigin(""), age(-1), photograph(""){}

VictimFile::VictimFile() : victimName(""), placeOfOrigin(""), age(-1), photograph(""){}

string VictimFile::toPlainString(){
    return victimName + " " + placeOfOrigin + " " + to_string(age) + " " + photograph;
}

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
    victimFile.age = stoi(ageString);
    victimFile.photograph = photoString;
    return inStream;
}
