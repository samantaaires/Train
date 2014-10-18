#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QMainWindow>
#include "Train.h"

namespace Ui {
class Controller;
}

class Controller : public QMainWindow
{
    Q_OBJECT

public:
    explicit Controller(QWidget *parent = 0);
    ~Controller();

public slots:
    void  updateInterface(int,int,int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Controller *ui;
    Train *trem1;
    Train *trem2;
    Train *trem3;
    Train *trem4;
    Train *trem5;
};
#endif // CONTROLER_H
