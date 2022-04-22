#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QSemaphore>
#include <mutex>

const int h = 250, v = 137;

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/

class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int,int,int,std::mutex *[7],int,int);  //construtor
    void speed(int &posicao);       //função que irá alterar o valor de velocidade
    void run();         //função a ser executada pela thread


//Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
    int x;           //posição X do trem na tela
    int y;           //posição Y do trem na tela
   int ID;          //ID do trem
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
   std::mutex *mutex[7]; //Array de mutexes que receberá o endereço dos mutexes do array "original" (o de mainwindow.h)
};

#endif // TREM_H
