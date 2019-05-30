#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <QVector>
#include <algorithm>


class Subject : public Observer
{
private:
    QVector<Observer*> observers;
public:
    void registerObserver(Observer* observer){
        observers.push_back(observer);
    }
    void unregisterObserver(Observer* observer){
        QVector<Observer*> temp;
        for(Observer* obs : observers){
            if(obs != observer){
                temp.push_back(obs);
            }
        }
        observers = temp;
    }
    void notify(){
        for(Observer* obs : observers){
            obs->update();
        }
    }
    Subject(){}

    void update() {}
};

#endif // SUBJECT_H
