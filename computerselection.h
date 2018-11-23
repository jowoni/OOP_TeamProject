#ifndef COMPUTERSELECTION_H
#define COMPUTERSELECTION_H
#include "part.h"
#include <list>

class ComputerSelection {
private:
    list<Part*> partSelection;
public:
    ComputerSelection();
    list<Part*> *getpartSelection();
};

#endif // COMPUTERSELECTION_H
