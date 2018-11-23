#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <compatibilityobserver.h>
#include <allpartandgamedata.h>
#include <partdata.h>
#include <iostream>
#include <QStandardItem>
#include "compatibilitysubject.h"
#include "part.h"
#include <string>
#include <controller.cpp>

MainWindow::MainWindow(CompatibilitySubject *cSub, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), cSub(cSub)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->choosePartTabs->setCurrentIndex(0);
    connect(ui->saveCombination, SIGNAL(clicked()), this, SLOT(shit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_initialize(AllPartAndGameData *apag){ //프로그램 시작시 part 콤보박스 초기화 or game list initialize
    list<PartData>::iterator pdIter;
    list<Part*>::iterator partIter;

    for(pdIter = apag->getAllPartDataList()->begin(); pdIter != apag->getAllPartDataList()->end(); pdIter++){
        if((pdIter->getPartName()).compare("cpu") == 0){
            update_compatibility_initialize(0, "cpu");
            for(partIter = pdIter->getPartDataList()->begin(); partIter != pdIter->getPartDataList()->end(); partIter++){
                ui->cpuCombo->addItem(QString::fromLocal8Bit((*partIter)->getName().c_str()));
            }
        }
        else if((pdIter->getPartName()).compare("mainboard") == 0){
            update_compatibility_initialize(0, "mainboard");
            for(partIter = pdIter->getPartDataList()->begin(); partIter != pdIter->getPartDataList()->end(); partIter++){
                //ui->mbCombo->addItem(QString::fromLocal8Bit((*partIter)->getName().c_str())); 처음에 메인보드 안나오고 cpu 선택 후 나옴
            }
        }
        else if((pdIter->getPartName()).compare("vga") == 0){
            update_compatibility_initialize(0, "vga");
            for(partIter = pdIter->getPartDataList()->begin(); partIter != pdIter->getPartDataList()->end(); partIter++){
                ui->vgaCombo->addItem(QString::fromLocal8Bit((*partIter)->getName().c_str()));
            }
        }
        else if((pdIter->getPartName()).compare("ram") == 0){
            update_compatibility_initialize(0, "ram");
            for(partIter = pdIter->getPartDataList()->begin(); partIter != pdIter->getPartDataList()->end(); partIter++){
                ui->ramCombo->addItem(QString::fromLocal8Bit((*partIter)->getName().c_str()));
            }
        }
        else if((pdIter->getPartName()).compare("hdd") == 0){
            update_compatibility_initialize(0, "hdd");
            for(partIter = pdIter->getPartDataList()->begin(); partIter != pdIter->getPartDataList()->end(); partIter++){
                ui->hddCombo->addItem(QString::fromLocal8Bit((*partIter)->getName().c_str()));
            }
        }
        else if((pdIter->getPartName()).compare("ssd") == 0){
            update_compatibility_initialize(0, "ssd");
            for(partIter = pdIter->getPartDataList()->begin(); partIter != pdIter->getPartDataList()->end(); partIter++){
                ui->ssdCombo->addItem(QString::fromLocal8Bit((*partIter)->getName().c_str()));
            }
        }
        else if((pdIter->getPartName()).compare("powersupply") == 0){
            update_compatibility_initialize(0, "powersupply");
            for(partIter = pdIter->getPartDataList()->begin(); partIter != pdIter->getPartDataList()->end(); partIter++){
                ui->powerCombo->addItem(QString::fromLocal8Bit((*partIter)->getName().c_str()));
            }
        }
    }
}

void MainWindow::update_compatibility(Part *p, string name){ //호환성 체크된 부품을 알맞은 콤보박스에 추가
    if(name.compare("cpu") == 0) ui->cpuCombo->addItem(QString::fromLocal8Bit(p->getName().c_str()));
    else if(name.compare("vga") == 0) ui->vgaCombo->addItem(QString::fromLocal8Bit(p->getName().c_str()));
    else if(name.compare("mainboard") == 0) ui->mbCombo->addItem(QString::fromLocal8Bit(p->getName().c_str()));
    else if(name.compare("ram") == 0) ui->ramCombo->addItem(QString::fromLocal8Bit(p->getName().c_str()));
    else if(name.compare("hdd") == 0) ui->hddCombo->addItem(QString::fromLocal8Bit(p->getName().c_str()));
    else if(name.compare("ssd") == 0) ui->ssdCombo->addItem(QString::fromLocal8Bit(p->getName().c_str()));
    else if(name.compare("powersupply") == 0) ui->powerCombo->addItem(QString::fromLocal8Bit(p->getName().c_str()));
}

void MainWindow::on_cpuCombo_activated(const QString &arg1){ //cpu콤보박스가 값이 선택되엇을대
    cSub->observerCpuComboChanged(arg1.toLocal8Bit().constData());
}

void MainWindow::update_compatibility_initialize(int existCpu, string name){ //호환성 체크되면 콤보박스 목록 지우고 빈 item 하나 넣기
    QStandardItemModel* model;
    QModelIndex firstIndex;
    QStandardItem* firstItem;

    if(name.compare("cpu") == 0) {
        ui->cpuCombo->clear();
        ui->cpuCombo->addItem("Choose");
        model = qobject_cast<QStandardItemModel*>(ui->cpuCombo->model());
        firstIndex = model->index(0, ui->cpuCombo->modelColumn(), ui->cpuCombo->rootModelIndex());
        firstItem = model->itemFromIndex(firstIndex);
        firstItem->setSelectable(false);
    }
    else if(name.compare("vga") == 0) {
        ui->vgaCombo->clear();
        ui->vgaCombo->addItem("Choose");
        model = qobject_cast<QStandardItemModel*>(ui->vgaCombo->model());
        firstIndex = model->index(0, ui->vgaCombo->modelColumn(), ui->vgaCombo->rootModelIndex());
        firstItem = model->itemFromIndex(firstIndex);
        firstItem->setSelectable(false);
    }
    else if(name.compare("mainboard") == 0) {
        ui->mbCombo->clear();
        if(existCpu == 0) ui->mbCombo->addItem("Select the CPU first"); // 맨 처음에는 이 문구가 메인보드 콤보박스에 뜸
        else  ui->mbCombo->addItem("Choose");                           // cpu 선택후에는 이 문구가 메인보드 콤보박스에 뜸
        model = qobject_cast<QStandardItemModel*>(ui->mbCombo->model());
        firstIndex = model->index(0, ui->mbCombo->modelColumn(), ui->mbCombo->rootModelIndex());
        firstItem = model->itemFromIndex(firstIndex);
        firstItem->setSelectable(false);
    }
    else if(name.compare("hdd") == 0) {
        ui->hddCombo->clear();
        ui->hddCombo->addItem("Choose");
        model = qobject_cast<QStandardItemModel*>(ui->hddCombo->model());
        firstIndex = model->index(0, ui->hddCombo->modelColumn(), ui->hddCombo->rootModelIndex());
        firstItem = model->itemFromIndex(firstIndex);
        firstItem->setSelectable(false);
    }
    else if(name.compare("ssd") == 0) {
        ui->ssdCombo->clear();
        ui->ssdCombo->addItem("Choose");
        model = qobject_cast<QStandardItemModel*>(ui->ssdCombo->model());
        firstIndex = model->index(0, ui->ssdCombo->modelColumn(), ui->ssdCombo->rootModelIndex());
        firstItem = model->itemFromIndex(firstIndex);
        firstItem->setSelectable(false);
    }
    else if(name.compare("ram") == 0) {
        ui->ramCombo->clear();
        ui->ramCombo->addItem("Choose");
        model = qobject_cast<QStandardItemModel*>(ui->ramCombo->model());
        firstIndex = model->index(0, ui->ramCombo->modelColumn(), ui->ramCombo->rootModelIndex());
        firstItem = model->itemFromIndex(firstIndex);
        firstItem->setSelectable(false);
    }
    else if(name.compare("powersupply") == 0) {
        ui->powerCombo->clear();
        ui->powerCombo->addItem("Choose");
        model = qobject_cast<QStandardItemModel*>(ui->powerCombo->model());
        firstIndex = model->index(0, ui->powerCombo->modelColumn(), ui->powerCombo->rootModelIndex());
        firstItem = model->itemFromIndex(firstIndex);
        firstItem->setSelectable(false);
    }
}

void MainWindow::on_cpuPrice_linkActivated(const QString &link)
{
    cout << "hello" <<endl;
}


void MainWindow::shit(){
    ui->saveCombination->setDisabled(true);
}
