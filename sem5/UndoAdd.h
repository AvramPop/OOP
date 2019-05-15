//
// Created by dani on 4/25/19.
//

#ifndef SEM5_UNDOADD_H
#define SEM5_UNDOADD_H


#include "Song.h"
#include "Repository.h"
#include "UndoAction.h"

class UndoAdd : public UndoAction{
    void executeUndo() override;

public:
    UndoAdd(Repository &repository, const Song &song);

    virtual ~UndoAdd();
};


#endif //SEM5_UNDOADD_H
