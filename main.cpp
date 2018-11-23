#include <QApplication>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "computerselection.h"
#include "allpartandgamedata.h"
#include "initializesubject.h"
#include "compatibilitysubject.h"
using namespace std;

int main(int argc, char *argv[]) {

    AllPartAndGameData apag;
    apag.openPartFiles();
    apag.openGameFiles();
    ComputerSelection cs;

    InitializeSubject iSub(&apag);
    CompatibilitySubject cSub(&apag);

    QApplication a(argc, argv);
    MainWindow w(&cSub);

    iSub.registerObserver(&w);
    cSub.registerObserver(&w);
    iSub.notify();

    w.show();
    return a.exec();
}
