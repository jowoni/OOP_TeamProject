#include <iostream>
#include <QObject>
#include <QPushButton>

using namespace std;

class SaveController : public QObject{

    QPushButton *button;

public:
    SaveController(QPushButton *button){
        this->button = button;
    }

public slots:
    void shit(){
        this->button->setDisabled(true);
    }
};
