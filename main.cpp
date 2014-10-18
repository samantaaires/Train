#include <QtCore/QCoreApplication>
#include <QApplication>

#include <controller.h>
#include <mainwindow.h>

#include <server.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
