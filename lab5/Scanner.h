//
// Created by dani on 3/27/19.
//

#ifndef LAB5_SCANNER_H
#define LAB5_SCANNER_H

#include <vector>
#include <string>
#include "VictimFileService.h"

class Scanner {
private:
    VictimFileService victimFileService;
    void list();

    void add(vector<string> inputAsTokens);

    void remove(string inputAsString);

    void mode(vector<string> inputAsTokens);

    void update(vector<string> inputAsTokens);
    void print(vector<string> inputAsTokens);
    void print(DynamicVector<VictimFile> victimFilesToPrint);
    VictimFile victimFileFromTokens(vector<string> tokens);
public:
    void runConsole();
};


#endif //LAB5_SCANNER_H
