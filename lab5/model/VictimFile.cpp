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

ostream &operator<<(ostream &os, const VictimFile &file){
    os << "Victim file victimName: " << file.victimName << " placeOfOrigin: " << file.placeOfOrigin << " age: " << file.age
       << " photograph: " << file.photograph;
    return os;
}

VictimFile::VictimFile(string victimName, string placeOfOrigin, int age, string photograph)
        : victimName(victimName), placeOfOrigin(placeOfOrigin), age(age), photograph(photograph){}

VictimFile::VictimFile(string name) : victimName(name), placeOfOrigin(""), age(-1), photograph(""){}

VictimFile::VictimFile() : victimName(""), placeOfOrigin(""), age(-1), photograph(""){}

string VictimFile::toPlainString(){
    return victimName + " " + placeOfOrigin + " " + to_string(age) + " " + photograph;
}
