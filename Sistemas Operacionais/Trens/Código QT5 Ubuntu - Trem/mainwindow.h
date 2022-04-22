#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mutex>
#include <QSemaphore>
#include "trem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::mutex *mutex[7]; //Array com os mutexes que controlarão cada área crítica.
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_A_valueChanged(int value);

    void on_horizontalSlider_B_valueChanged(int value);

    void on_horizontalSlider_C_valueChanged(int value);

    void on_horizontalSlider_D_valueChanged(int value);

    void on_horizontalSlider_E_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem *tremA;
    Trem *tremB;
    Trem *tremC;
    Trem *tremD;
    Trem *tremE;
};

#endif // MAINWINDOW_H
