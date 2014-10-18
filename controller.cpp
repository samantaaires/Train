#include "controller.h"

#include "mainwindow.h"
#include <QApplication>

Controller::Controller(){
}


int Controller::startController(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
