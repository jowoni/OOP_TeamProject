#ifndef INITIALIZESUBJECT_H
#define INITIALIZESUBJECT_H

#include <iostream>
#include "allpartandgamedata.h"
#include <vector>
#include "compatibilityobserver.h"
#include "computerselection.h"
#include <initializeobserver.h>

class InitializeSubject
{
    AllPartAndGameData *apag;
    vector<InitializeObserver*> views;
public:
    InitializeSubject(AllPartAndGameData *apag) : apag(apag){}

    void registerObserver(InitializeObserver *initObs){
        views.push_back(initObs);
    }

    void notify(){
        for (vector<int>::size_type i = 0; i < views.size(); i++){
            views[i]->update_initialize(apag);
        }
    }

};

#endif // INITIALIZESUBJECT_H
