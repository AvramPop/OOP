//
// Created by dani on 3/27/19.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "Scanner.h"

void Scanner::runConsole(){
    victimFileService.addVictimFile(VictimFile("dani", "ia", 8, "bani")); //todo remove this
    victimFileService.addVictimFile(VictimFile("ana", "are", 9, "mere"));
    char userInput[1000];
    string inputAsString;
    string command;
    bool inputNotExit = true;
    while(inputNotExit){
        scanf(" %[^\n]s", userInput);
        vector<string> inputAsTokens;
        inputAsString = userInput;
        string delimiter = " ";
        command = inputAsString.substr(0, inputAsString.find(delimiter));
        auto indexAfterCommand = inputAsString.find(" ") + 1;
        inputAsString = inputAsString.substr(indexAfterCommand);
        stringstream inputAsStringStream(inputAsString);
        string token;
        while(getline(inputAsStringStream, token, ',')){
            token = std::regex_replace(token, std::regex("^ +"), "");
            inputAsTokens.push_back(token);
        }
        if(command == "exit"){
            cout << "exit";
            inputNotExit = false;
        } else if(command == "list"){
            list();
        } else if(command == "add"){
            add(inputAsTokens);
        } else if(command == "update"){
            update(inputAsTokens);
        } else if(command == "mode"){
            mode(inputAsTokens);
        } else if(command == "delete"){
            remove(inputAsTokens);
        }
    }
}

void Scanner::list(){
    print(victimFileService.getList());
}

void Scanner::add(vector<string> inputAsTokens){
    victimFileService.addVictimFile(victimFileFromTokens(inputAsTokens));
}

void Scanner::remove(vector<string> inputAsTokens){
    victimFileService.removeVictimFile(inputAsTokens[0]); // todo change this, take whole second part of input
}

void Scanner::mode(vector<string> inputAsTokens){
    cout << "selecting mode\n";
}

void Scanner::update(vector<string> inputAsTokens){ // todo something can break here and throw logic error
    victimFileService.updateVictimFile(inputAsTokens[0], victimFileFromTokens(inputAsTokens));
}

void Scanner::print(vector<string> inputAsTokens){
    for(const auto &inputAsToken : inputAsTokens){
        cout << inputAsToken << " ";
    }
    cout << endl;
}

void Scanner::print(DynamicVector<VictimFile> victimFilesToPrint){
    for(int i = 0; i < victimFilesToPrint.getSize(); i++){
        cout << victimFilesToPrint[i].toPlainString() << endl;
    }
}

VictimFile Scanner::victimFileFromTokens(vector<string> tokens){
    return VictimFile(tokens[0], tokens[1], atoi(tokens[2].data()), tokens[3]);
}
