//
// Created by dani on 3/28/19.
//

#ifndef LAB5_MODE_H
#define LAB5_MODE_H

#include <string>
using namespace std;
class Mode {
private:
    string mode;
public:
    Mode(string mode) : mode(mode){};
    Mode(){ mode = "defaultNoMode"; };
    void setMode(string mode){ this->mode = mode; }
    string getMode(){ return mode; }
};


#endif //LAB5_MODE_H
