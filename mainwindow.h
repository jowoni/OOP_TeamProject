#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <compatibilityobserver.h>
#include <initializeobserver.h>
#include <allpartandgamedata.h>
#include "compatibilitysubject.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public CompatibilityObserver, public InitializeObserver //관찰자
{
    Q_OBJECT
    CompatibilitySubject *cSub;
public:
    explicit MainWindow(CompatibilitySubject *cSub, QWidget *parent = nullptr); //subject 인자 추가
    ~MainWindow();
    void update_compatibility(Part *p, string name);
    void update_compatibility_initialize(int existCpu, string name);
    void update_initialize(AllPartAndGameData *apag);

private slots:
    void on_cpuCombo_activated(const QString &arg1);
    void shit();
    void on_cpuPrice_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
