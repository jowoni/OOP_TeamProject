#ifndef COMPATIBILITYOBSERVER_H
#define COMPATIBILITYOBSERVER_H

#include "part.h"
class CompatibilitySubject;

class CompatibilityObserver
{
private:
    CompatibilitySubject *model;
public:
    virtual ~CompatibilityObserver(){}
    virtual void update_compatibility(Part *p, string name) = 0;
    virtual void update_compatibility_initialize(int existCpu, string name) = 0;
    CompatibilitySubject* getCompatibilitySubject(){
        return model;
    }
};

#endif // COMPATIBILITYOBSERVER_H
