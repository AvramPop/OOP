//
// Created by dani on 4/25/19.
//

#include "UndoAdd.h"

void UndoAdd::executeUndo(){
    repository.removeSong(song);
}

UndoAdd::~UndoAdd(){

}

UndoAdd::UndoAdd(Repository &repository, const Song &song) : UndoAction(repository, song){}
