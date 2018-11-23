#ifndef INITIALIZEOBSERVER_H
#define INITIALIZEOBSERVER_H
#include <allpartandgamedata.h>

class InitializeObserver
{
public:
    virtual ~InitializeObserver(){}
    virtual void update_initialize(AllPartAndGameData *apag) = 0;
};

#endif // INITIALIZEOBSERVER_H
