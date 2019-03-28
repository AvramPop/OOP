//
// Created by dani on 3/27/19.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "Scanner.h"

void Scanner::runConsole(){
    char userInput[1000];
    string inputAsString;
    string command;
    bool inputNotExit = true;
    bool isFirstToken;
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
        string nameToken;
        isFirstToken = true;
        while(getline(inputAsStringStream, token, ',')){
            token = std::regex_replace(token, std::regex("^ +"), "");
            if(isFirstToken){
                isFirstToken = false;
                nameToken = token;
            }
            inputAsTokens.push_back(token);
        }
        if(command == "exit"){
            cout << "exit";
            inputNotExit = false;
        } else if(command == "list"){
            list();
        } else if(command == "add"){
            if(currentMode.getMode() == "A"){
                add(inputAsTokens);
            }
        } else if(command == "update"){
            if(currentMode.getMode() == "A"){
                update(nameToken, inputAsTokens);
            }
        } else if(command == "mode"){
            setMode(inputAsTokens);
        } else if(command == "delete"){
            if(currentMode.getMode() == "A"){
                remove(nameToken);
            }
        }
    }
}

void Scanner::list(){
    print(victimFileService.getList());
}

void Scanner::add(vector<string> inputAsTokens){
    if(isValidInput(inputAsTokens)){
        victimFileService.addVictimFile(victimFileFromTokens(inputAsTokens));
    }
}

void Scanner::remove(string victimName){
    victimFileService.removeVictimFile(victimName);
}

void Scanner::setMode(vector<string> inputAsTokens){
    currentMode.setMode(inputAsTokens[0]);
}

void Scanner::update(string victimName, vector<string> inputAsTokens){ // todo something can break here and throw logic error
    if(isValidInput(inputAsTokens)){
        victimFileService.updateVictimFile(victimName, victimFileFromTokens(inputAsTokens));
    }
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

bool Scanner::isValidInput(vector<string> input){
    return isNumber(input[2]);
}

bool Scanner::isNumber(string potentialNumber) {
    char** endPointer;
    strtol(potentialNumber.data(), endPointer, 10);
    return  **endPointer == '\0';
}
