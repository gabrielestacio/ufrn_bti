#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSemaphore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Alocação do array de mutexes
    for(int i = 0; i < 7; i++){
        mutex[i] = new std::mutex;
    }

    //Cria o trem com seu (ID, posição X, posição Y, vetor de mutexes e mutexes que precisam ser inicializados junto com o trem (explicação melhor em trem.cpp))
    tremA = new Trem(1,60,30, mutex, 0, 0);
    tremB = new Trem(2,330,30, mutex, 1, 0);
    tremC = new Trem(3,600,30, mutex, 2, 0);
    tremD = new Trem(4,190,150, mutex, 3, 0);
    tremE = new Trem(5,460,150, mutex, 5, 7);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(tremA,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(tremB,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(tremC,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(tremD,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(tremE,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem 1
        ui->label_tremA->setGeometry(x,y,20,20);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem 2
        ui->label_tremB->setGeometry(x,y,20,20);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem 3
        ui->label_tremC->setGeometry(x,y,20,20);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem 4
        ui->label_tremD->setGeometry(x,y,20,20);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem 5
        ui->label_tremE->setGeometry(x,y,20,20);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */
void MainWindow::on_pushButton_clicked()
{
    tremA->start();
    tremB->start();
    tremC->start();
    tremD->start();
    tremE->start();
}

/*
 * Ao clicar, trens param execução
 */
void MainWindow::on_pushButton_2_clicked()
{
    tremA->terminate();
    tremB->terminate();
    tremC->terminate();
    tremD->terminate();
    tremE->terminate();
}

//Controla a velocidade do trem A
void MainWindow::on_horizontalSlider_A_valueChanged(int value)
{
    tremA->speed(value);
}

//Controla a velocidade do trem B
void MainWindow::on_horizontalSlider_B_valueChanged(int value)
{
    tremB->speed(value);
}

//Controla a velocidade do trem C
void MainWindow::on_horizontalSlider_C_valueChanged(int value)
{
    tremC->speed(value);
}

//Controla a velocidade do trem D
void MainWindow::on_horizontalSlider_D_valueChanged(int value)
{
    tremD->speed(value);
}

//Controla a velocidade do trem E
void MainWindow::on_horizontalSlider_E_valueChanged(int value)
{
    tremE->speed(value);
}
