#include "computerselection.h"
#include "part.h"

ComputerSelection::ComputerSelection(){

}

list<Part*> *ComputerSelection::getpartSelection() {
    return &partSelection;
}
