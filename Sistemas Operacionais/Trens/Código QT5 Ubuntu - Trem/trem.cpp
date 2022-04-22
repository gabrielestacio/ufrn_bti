#include "mainwindow.h"
#include "trem.h"
#include <QtCore>
#include <QMutex>
#include <QSemaphore>

//Construtor
Trem::Trem(int ID, int x, int y, std::mutex*(mutex)[7], int a, int b){
    this->ID = ID;
    this->x = x;
    this->y = y;
    for(int i = 0; i < 7; i++){
        this->mutex[i] = mutex[i];
    }

    /*
    Esses inteiros a e b passados na construção do trem em mainwindow.cpp indicam mutexes que precisam ser inicializados antes
    de executar. Se o valor for 0, então, nenhum mutex será inicializado. Se o valor for diferente de zero, então o mutex correspondente a
    área crítica representada pelo valor passado será inicializado.

    E porque inicializar esse mutexes? Porque, com exceção do trem A, todos os trens iniciam já dentro de áreas críticas. Logo, como o unlock()
    do mutex é feito assim que ele sai da área crítica, esses trens já começariam dando um unlock() sem antes ter acontecido um lock(),
    destruindo o mutex correspondente. Logo, ao construir o trem, os mutexes que este trem manipula e que dá unlock() antes do lock() são
    inicializados com um lock(), para que o mutex correspondente não seja destruído.

    Isso não altera o percurso dos trens, porque a partir da segunda execução do while, quando cada um desses trens sai da área crítica, já é
    feito o unlock() do mutex.

    São dois inteiros porque o trem E começa dentro de duas áreas críticas (5 e 7, ou mutex[4] e mutex[6]).
    */
    if(a != 0){
        mutex[a-1]->lock();
    }
    if(b != 0){
        mutex[b-1]->lock();
    }

    velocidade = 100;
}

//Função que muda a velocidade (Essa já tá ok)
void Trem::speed(int &posicao){
    velocidade = posicao;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem A
            while((x < 330) && (y == 30)){
                /*
                O mutex da zona três é lockado antes do da zona um para evitar deadlocks (essa lógica também acontece no trem C e no trem E para evitar deadlocks).
                Por mais que o trem A vá passar primeiro pela zona 1, o mutex da zona 3 é feito antes para que não aconteça de A fazer o lock da zona 1,
                e depois que fizer esse lock, ficar bloqueado esperando a zona 3 desocupar, enquanto D, que ocupa a zona 3, espera a zona 4 desocupar, que está
                sendo ocupada por B que espera a zona 1 desocupar, mas a zona 1 foi lockada por A. Isso geraria um deadlock.
                Com o lock da zona 3 sendo feito antes do da zona 1, garante-se que o caminho todo estará disponível para A e que não acontecerá um deadlock.
                */
                if(x == 310){ //Imediatamente antes de entrar na zona crítica 1
                    mutex[2]->lock();
                    mutex[0]->lock();
                }
                x += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 330) && (y < 150)){
                y += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x > 60) && (y == 150)){
                if(x == 310){ //Imediatamente depois de sair da zona crítica 1
                    mutex[0]->unlock();
                }
                if(x == 170){
                    mutex[2]->unlock(); //Imediatamente depois de sair da zona crítica 3
                }
                x -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 60) && (y > 30)){
                y -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            break;
        case 2: //Trem B
            while((x < 600) && (y == 30)){
                if(x == 350){ //Imediatamente depois de sair da zona crítica 1
                    mutex[0]->unlock();
                }
                if(x == 580){ //Imediatamente antes de entrar na zona crítica 2
                    mutex[1]->lock();
                }
                x += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 600) && (y < 150)){
                if(y == 130){ //Imediatamente antes de entrar na zona crítica 5
                    mutex[4]->lock();
                }
                y += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x > 330) && (y == 150)){
                if(x == 350){ //Imediatamente antes de entrar na zona crítica 1
                    mutex[0]->lock();
                }
                if(x == 440){ //Imediatamente depois de sair da zona crítica 5
                    mutex[4]->unlock();
                }
                if(x == 480){ //Imediatamente antes de entrar na zona crítica 4
                    mutex[3]->lock();
                }
                if(x == 580){ //Imediatamente depois de sair da zona crítica 2
                    mutex[1]->unlock();
                }
                x -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 330) && (y > 30)){
                if(y == 130){ //Imediatamente depois de sair da zona crítica 4
                    mutex[3]->unlock();
                }
                y -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            break;
        case 3: //Trem C
            while((x < 870) && (y == 30)){
                if(x == 620){ //Imediatamente depois de sair da zona crítica 2
                    mutex[1]->unlock();
                }
                x += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 870) && (y < 150)){
                y += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x > 600) && (y == 150)){
                if(x == 750){ //Imediatamente antes de entrar na zona crítica 6
                    mutex[1]->lock();
                    mutex[5]->lock();
                }
                x -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 600) && (y > 30)){
                if(y == 130){ //Imediatamente depois de sair da zona crítica 6
                    mutex[5]->unlock();
                }
                y -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            break;
        case 4: //Trem D
            while((x < 460) && (y == 150)){
                if(x == 310){ //Imediatamente antes de entrar na zona crítica 4
                    mutex[3]->lock();
                }
                if(x == 350){ //Imediatamente depois de sair da zona crítica 3
                    mutex[2]->unlock();
                }
                if(x == 440){ //Imediatamente antes de entrar na zona crítica 7
                    mutex[6]->lock();
                }
                x += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 460) && (y < 270)){
                if(y == 170){ //Imediatamente depois de sair da zona crítica 4
                    mutex[3]->unlock();
                }
                y += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x > 190) && (y == 270)){
                if(x == 440){ //Imediatamente depois de sair da zona crítica 7
                    mutex[6]->unlock();
                }
                x -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 190) && (y > 150)){
                if(y == 170){ //Imediatamente antes de entrar na zona crítica 3
                    mutex[2]->lock();
                }
                y -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            break;
        case 5: //Trem E
            while((x < 730) && (y == 150)){
                if(x == 480){ //Imediatamente depois de sair da zona crítica 7
                    mutex[6]->unlock();
                }
                if(x == 580){ //Imediatamente antes de entrar na zona crítica 6
                    mutex[5]->lock();
                }
                if(x == 620){ //Imediatamente depois de sair da zona crítica 5
                    mutex[4]->unlock();
                }
                x += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 730) && (y < 270)){
                if(y == 170){ //Imediatamente depois de sair da zona crítica 6
                    mutex[5]->unlock();
                }
                y += 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x > 460) && (y == 270)){
                if(x == 480){ //Imediatamente antes de entrar na zona crítica 7
                    mutex[4]->lock();
                    mutex[6]->lock();
                }
                x -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            while((x == 460) && (y > 150)){
                y -= 10;
                emit updateGUI(ID, x,y);
                msleep(200 - velocidade);
            }
            break;
        default:
            break;
        }
    }
}



