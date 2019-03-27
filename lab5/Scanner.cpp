//
// Created by dani on 3/27/19.
//

#include <iostream>
#include "Scanner.h"

void Scanner::runConsole(VictimFileService victimFileService){
    char userInput[1000];
    string inputAsString;
    string command;
    bool inputNotExit = true;
    while(inputNotExit){
        scanf(" %[^\n]s", userInput);
        inputAsString = userInput;
        string delimiter = " ";
        command = inputAsString.substr(0, inputAsString.find(delimiter));
        if(command == "exit"){
            inputNotExit = false;
        } else if(command == "list"){
            cout << "listing\n";
        } else if(command == "add"){
            cout << "adding\n";
        } else if(command == "update"){
            cout << "updating\n";
        } else if(command == "mode"){
            cout << "selecting mode\n";
        } else if(command == "delete"){
            cout << "deleting\n";
        }
    }
}
