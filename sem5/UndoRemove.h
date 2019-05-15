//
// Created by dani on 4/25/19.
//

#ifndef SEM5_UNDOREMOVE_H
#define SEM5_UNDOREMOVE_H


#include "Song.h"
#include "Repository.h"
#include "UndoAction.h"

class UndoRemove : public UndoAction {
    void executeUndo() override;

public:
    UndoRemove(Repository &repository, const Song &song);

    virtual ~UndoRemove();
};


#endif //SEM5_UNDOREMOVE_H
