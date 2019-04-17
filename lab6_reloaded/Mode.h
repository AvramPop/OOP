//
// Created by dani on 4/17/19.
//

#ifndef LAB6_RELOADED_MODE_H
#define LAB6_RELOADED_MODE_H

#include <string>
using namespace std;
/**
 * Stub class representing user access mode in the app.
 * */
class Mode {
private:
    string mode;
public:
    Mode(string mode) : mode(mode){};
    Mode(){ mode = "defaultNoMode"; };
    void setMode(string mode){ this->mode = mode; }
    string getMode(){ return mode; }
};


#endif //LAB6_RELOADED_MODE_H
