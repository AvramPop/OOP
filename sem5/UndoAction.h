//
// Created by dani on 4/25/19.
//

#ifndef SEM5_UNDOACTION_H
#define SEM5_UNDOACTION_H


#include "Repository.h"

class UndoAction {
public:
    Repository& repository;
    Song song;
    virtual ~UndoAction();
    virtual void executeUndo() = 0;

    UndoAction(Repository &repository, const Song &song);
};


#endif //SEM5_UNDOACTION_H
