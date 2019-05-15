//
// Created by dani on 4/25/19.
//

#include "UndoAction.h"

UndoAction::UndoAction(Repository &repository, const Song &song) : repository(repository), song(song){}

UndoAction::~UndoAction(){

}
