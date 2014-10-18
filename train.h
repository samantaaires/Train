#ifndef TRAIN_H
#define TRAIN_H
#include <QThread>
#include <QSemaphore>


class Train: public QThread{ //classe thread é na verdade a classe trem
 Q_OBJECT
public:
    Train(int, QSemaphore*, QSemaphore*, QSemaphore*, QSemaphore*, QSemaphore*, QSemaphore*, QSemaphore*);
    void run();
    void stop();
    void restart();
    void addSpeed();
    void removeSpeed();
    void enter_critical_zone(int, int);
    void leave_critical_zone(int, int);
    QSemaphore * semaphore1;
    QSemaphore * semaphore2;
    QSemaphore * semaphore3;
    QSemaphore * semaphore4;
    QSemaphore * semaphore5;
    QSemaphore * semaphore6;
    QSemaphore * semaphore7;

signals:
    void updateGUI(int,int,int); //id,x,y são os atributos, emite o sinal quando quiser atualizar a interface grafica

private:
   int x;
   int y;
   int locationX;
   int locationY;
   int ID; //diferenciar os trens
   int speed;
   bool stoped;
   bool semaphores_aquired[7];
};
#endif // TRAIN_H
