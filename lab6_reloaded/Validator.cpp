//
// Created by dani on 4/26/19.
//

#include <algorithm>
#include "Validator.h"
#include "Exception.h"

bool Validator::validateVictimFile(string name, string place, string age, string photo){
    bool isValid = true;
    if(age.empty()){
        isValid = false;
    } else {
        if(!all_of(age.begin(), age.end(), ::isdigit)){ // checks that all chars are digits
            isValid = false;
        }
    }
    if(name.empty() || place.empty() || photo.empty()) isValid = false;
    return isValid;
}
