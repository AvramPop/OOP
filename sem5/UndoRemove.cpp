//
// Created by dani on 4/25/19.
//

#include "UndoRemove.h"

void UndoRemove::executeUndo(){
    repository.addSong(song);
}

UndoRemove::~UndoRemove(){

}

UndoRemove::UndoRemove(Repository &repository, const Song &song) : UndoAction(repository, song){}
