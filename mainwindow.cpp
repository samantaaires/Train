#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSemaphore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSemaphore * s1 = new QSemaphore(1); //Zona de colisao entre o trem 1 e 2
    QSemaphore * s2 = new QSemaphore(1); //Zona de colisao entre o trem 1 e 4
    QSemaphore * s3 = new QSemaphore(1); //Zona de colisao entre o trem 2 e 4
    QSemaphore * s4 = new QSemaphore(1); //Zona de colisao entre o trem 4 e 5
    QSemaphore * s5 = new QSemaphore(1); //Zona de colisao entre o trem 2 e 5
    QSemaphore * s6 = new QSemaphore(1); //Zona de colisao entre o trem 2 e 3
    QSemaphore * s7 = new QSemaphore(1); //Zona de colisao entre o trem 3 e 5

    trem1 = new Train(1, s1, s2, s3, s4, s5, s6, s7);
    trem2 = new Train(2, s1, s2, s3, s4, s5, s6, s7);
    trem3 = new Train(3, s1, s2, s3, s4, s5, s6, s7);
    trem4 = new Train(4, s1, s2, s3, s4, s5, s6, s7);
    trem5 = new Train(5, s1, s2, s3, s4, s5, s6, s7);



    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int))); //trem1 conecta ao sinal e toda vez
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
}


void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1:
        ui->label->setGeometry(x,y,25,25); //

        break;
    case 2:
        ui->label_4->setGeometry(x,y,25,25);

        break;

    case 3:
        ui->label_6->setGeometry(x,y,25,25);

        break;

    case 4:
        ui->label_10->setGeometry(x,y,25,25);

        break;

    case 5:
        ui->label_11->setGeometry(x,y,25,25);

        break;

        default:
        break;

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() //se apertar o botao começa a rodar as threads
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    trem1->addSpeed();
}

void MainWindow::on_pushButton_3_clicked()
{
    trem1->removeSpeed();
}

void MainWindow::on_pushButton_4_clicked()
{
    trem1->stop();
}

void MainWindow::on_pushButton_5_clicked()
{
    if (!trem1->isRunning())
        trem1->start();
    else
        trem1->restart();
}

void MainWindow::on_pushButton_8_clicked()
{
    trem2->stop();
}

void MainWindow::on_pushButton_6_clicked()
{
    if (!trem2->isRunning())
        trem2->start();
    else
        trem2->restart();
}

void MainWindow::on_pushButton_9_clicked()
{
    trem2->addSpeed();
}

void MainWindow::on_pushButton_7_clicked()
{
    trem2->removeSpeed();
}

void MainWindow::on_pushButton_12_clicked()
{
    trem3->stop();
}

void MainWindow::on_pushButton_10_clicked()
{
    if (!trem3->isRunning())
        trem3->start();
    else
        trem3->restart();
}

void MainWindow::on_pushButton_13_clicked()
{
    trem3->addSpeed();
}

void MainWindow::on_pushButton_11_clicked()
{
    trem3->removeSpeed();
}

void MainWindow::on_pushButton_16_clicked()
{
    trem4->stop();
}

void MainWindow::on_pushButton_14_clicked()
{
    if (!trem4->isRunning())
        trem4->start();
    else
        trem4->restart();
}

void MainWindow::on_pushButton_17_clicked()
{
    trem4->addSpeed();
}

void MainWindow::on_pushButton_15_clicked()
{
    trem4->removeSpeed();
}

void MainWindow::on_pushButton_20_clicked()
{
    trem5->stop();
}

void MainWindow::on_pushButton_18_clicked()
{
    if (!trem5->isRunning())
        trem5->start();
    else
        trem5->restart();
}

void MainWindow::on_pushButton_21_clicked()
{
    trem5->addSpeed();
}

void MainWindow::on_pushButton_19_clicked()
{
    trem5->removeSpeed();
}
