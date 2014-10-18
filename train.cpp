#include "train.h"
#include <QtCore>
#include <QDebug>


Train::Train(int ID, QSemaphore * s1, QSemaphore * s2, QSemaphore * s3, QSemaphore * s4, QSemaphore * s5, QSemaphore * s6, QSemaphore * s7){
    this->ID = ID; //quando cria só passa o ID
    this->speed = 1;

    this->semaphore1 = s1;
    this->semaphores_aquired[0] = false;

    this->semaphore2 = s2;
    this->semaphores_aquired[1] = false;

    this->semaphore3 = s3;
    this->semaphores_aquired[2] = false;

    this->semaphore4 = s4;
    this->semaphores_aquired[3] = false;

    this->semaphore5 = s5;
    this->semaphores_aquired[4] = false;

    this->semaphore6 = s6;
    this->semaphores_aquired[5] = false;

    this->semaphore7 = s7;
    this->semaphores_aquired[6] = false;

    switch(ID){
        case 1:
            this->locationX = 100;
            this->locationY = 20;
            break;
        case 2:
            this->locationX = 250;
            this->locationY = 20;
            break;
        case 3:
            this->locationX = 400;
            this->locationY = 20;
            break;
        case 4:
            this->locationX = 175;
            this->locationY = 130;
            break;
        case 5:
            this->locationX = 325;
            this->locationY = 130;
            break;
        default:
            break;
    }
}

void Train::addSpeed(){
    this->speed += 1;
}

void Train::stop(){
    this->stoped = true;
}

void Train::restart(){
    this->stoped = false;
}

void Train::removeSpeed(){
    if (this->speed > 1){
        this->speed -= 1;
    }
}

void Train::run(){ //onde as coisas acontecem. É onde vai fazer a logica de quando o trem ta na posição eu faço alguma coisa no semaforo
    x = locationX;
    y = locationY;
    this->stoped = false; //pra ficar rodando
    while(true){
        while(this->stoped == false){
            emit updateGUI(ID, x,y);
            enter_critical_zone(x, y);
            qDebug()<<x<<y;
            if(x < locationX+150 && y == locationY ){ //se ainda nao atingiu o limite eu vou incrementando
                x++;
            }else if (x == locationX+150 && y < locationY+110){ //quando aitnge eu volto pra 0
               y++;
            }else if(y == locationY+110 && x > locationX){
                x--;
            }else{
                y--;
            }
            leave_critical_zone(x, y);
            usleep(10000/speed);
        }
        usleep(100000);
    }
}

void Train::enter_critical_zone(int x, int y){
    switch(ID){
        case 1:
            if (x == 230 && y == 20){ // conflito com o trem 2
                semaphore1->acquire(1);
                this->semaphores_aquired[0] = true;

                semaphore2->acquire(1); //conflito com o trem 4
                this->semaphores_aquired[1] = true;
            }
            break;
        case 2:
            if (x == 370 && y == 20){ //conflito com o trem 1
                semaphore1->acquire(1);
                this->semaphores_aquired[0] = true;

                semaphore3->acquire(1);
                this->semaphores_aquired[2] = true; // conflito com o trem 4

                semaphore5->acquire(1); // conflito com o trem 5
                this->semaphores_aquired[4] = true;

                semaphore6->acquire(1); // conflito com o trem 6
                this->semaphores_aquired[5] = true;
            }
            break;
        case 3:
            if (x == 511 && y == 130){ //conflito com o trem 2
                semaphore6->acquire(1);
                this->semaphores_aquired[5] = true;

                semaphore7->acquire(1);
                this->semaphores_aquired[6] = true;
            }
            break;
        case 4:
            if (x == 175 && y == 167){
                semaphore2->acquire(1); // conflito com o trem 1
                this->semaphores_aquired[1] = true;

                semaphore3->acquire(1); // conflito com o trem 2
                this->semaphores_aquired[2] = true;

                semaphore4->acquire(1); // conflito com o trem 5
                this->semaphores_aquired[3] = true;
            }
            break;
        case 5:
            if (x == 357 && y == 240){
                semaphore4->acquire(1); //conflito com o trem 4
                this->semaphores_aquired[3] = true;

                semaphore5->acquire(1); //conflito com o trem 2
                this->semaphores_aquired[4] = true;

                semaphore7->acquire(1); //conflito com o trem 2
                this->semaphores_aquired[6] = true;
            }
            break;
        default:
            break;

    }
}

void Train::leave_critical_zone(int x, int y){
    switch(ID){
        case 1:
            if (x == 230 && y == 130)
                if(semaphores_aquired[0]){
                     semaphore1->release();
                     semaphores_aquired[0] = false;
                }
            if (x == 150 && y == 130)
                if(semaphores_aquired[1]){
                     semaphore2->release();
                     semaphores_aquired[1] = false;
                }
            break;
        case 2:
            if (x == 280 && y == 20)
               if(semaphores_aquired[0]){
                    semaphore1->release();
                    semaphores_aquired[0] = false;
               }
            if (x == 250 && y == 92)
               if(semaphores_aquired[2]){
                    semaphore3->release();
                    semaphores_aquired[2] = false;
               }
            if(x == 286 && y == 130)
               if(semaphores_aquired[4]){
                    semaphore5->release();
                    semaphores_aquired[4] = false;
               }
            if(x == 361 && y == 130)
               if(semaphores_aquired[5]){
                    semaphore6->release();
                    semaphores_aquired[5] = false;
               }
            break;

        case 3:
            if (x == 423 && y == 20)
               if(semaphores_aquired[5]){
                    semaphore6->release();
                    semaphores_aquired[5] = false;
                }
            if(x == 400 && y == 91)
                if(semaphores_aquired[6]){
                    semaphore7->release();
                    semaphores_aquired[6] = false;
               }
            break;
        case 4:
            if (x == 280 && y == 130)
               if(semaphores_aquired[1]){
                    semaphore2->release();
                    semaphores_aquired[1] = false;
               }
            if (x == 325 && y == 143)
                if(semaphores_aquired[2]){
                     semaphore3->release();
                     semaphores_aquired[2] = false;
                }
            if (x == 288 && y == 240)
                if(semaphores_aquired[3]){
                     semaphore4->release();
                     semaphores_aquired[3] = false;
                }
            break;
        case 5:
            if (x == 350 && y == 130)
                if(semaphores_aquired[3]){
                     semaphore4->release();
                     semaphores_aquired[3] = false;
                }
            if(x == 437 && y == 130)
                if(semaphores_aquired[4]){
                     semaphore5->release();
                     semaphores_aquired[4] = false;
                }
            if(x == 475 && y == 166)
                if(semaphores_aquired[6]){
                     semaphore7->release();
                     semaphores_aquired[6] = false;
                }
            break;
        default:
            break;
    }
}
