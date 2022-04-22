/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_tremA;
    QLabel *label_trilho2AB;
    QLabel *label_trilho4ABD;
    QLabel *label_trilho3AB;
    QLabel *label_trilho1A;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_trilho3BC;
    QLabel *label_trilho2BAC;
    QLabel *label_trilho4BADEC;
    QLabel *label_tremB;
    QLabel *label_trilho2CB;
    QLabel *label_trilho3C;
    QLabel *label_trilho4CBE;
    QLabel *label_trilho1DA;
    QLabel *label_trilho4DE;
    QLabel *label_trilho3DBE;
    QLabel *label_trilho3EC;
    QLabel *label_trilho4ED;
    QLabel *label_tremC;
    QLabel *label_tremD;
    QLabel *label_tremE;
    QSlider *horizontalSlider_B;
    QSlider *horizontalSlider_C;
    QSlider *horizontalSlider_E;
    QSlider *horizontalSlider_D;
    QSlider *horizontalSlider_A;
    QLabel *label_A;
    QLabel *label_B;
    QLabel *label_C;
    QLabel *label_D;
    QLabel *label_E;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1034, 613);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_tremA = new QLabel(centralWidget);
        label_tremA->setObjectName(QString::fromUtf8("label_tremA"));
        label_tremA->setGeometry(QRect(60, 30, 20, 20));
        QPalette palette;
        QBrush brush(QColor(239, 41, 41, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        label_tremA->setPalette(palette);
        label_tremA->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(239, 41, 41)}"));
        label_tremA->setAlignment(Qt::AlignCenter);
        label_trilho2AB = new QLabel(centralWidget);
        label_trilho2AB->setObjectName(QString::fromUtf8("label_trilho2AB"));
        label_trilho2AB->setGeometry(QRect(80, 30, 250, 20));
        label_trilho2AB->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho4ABD = new QLabel(centralWidget);
        label_trilho4ABD->setObjectName(QString::fromUtf8("label_trilho4ABD"));
        label_trilho4ABD->setGeometry(QRect(80, 150, 250, 20));
        label_trilho4ABD->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho3AB = new QLabel(centralWidget);
        label_trilho3AB->setObjectName(QString::fromUtf8("label_trilho3AB"));
        label_trilho3AB->setGeometry(QRect(330, 30, 20, 140));
        label_trilho3AB->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho1A = new QLabel(centralWidget);
        label_trilho1A->setObjectName(QString::fromUtf8("label_trilho1A"));
        label_trilho1A->setGeometry(QRect(60, 30, 20, 140));
        label_trilho1A->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 500, 99, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 500, 98, 27));
        label_trilho3BC = new QLabel(centralWidget);
        label_trilho3BC->setObjectName(QString::fromUtf8("label_trilho3BC"));
        label_trilho3BC->setGeometry(QRect(600, 30, 20, 140));
        label_trilho3BC->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho2BAC = new QLabel(centralWidget);
        label_trilho2BAC->setObjectName(QString::fromUtf8("label_trilho2BAC"));
        label_trilho2BAC->setGeometry(QRect(350, 30, 250, 20));
        label_trilho2BAC->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho4BADEC = new QLabel(centralWidget);
        label_trilho4BADEC->setObjectName(QString::fromUtf8("label_trilho4BADEC"));
        label_trilho4BADEC->setGeometry(QRect(350, 150, 250, 20));
        label_trilho4BADEC->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_tremB = new QLabel(centralWidget);
        label_tremB->setObjectName(QString::fromUtf8("label_tremB"));
        label_tremB->setGeometry(QRect(330, 30, 20, 20));
        label_tremB->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(52, 101, 164)}"));
        label_tremB->setAlignment(Qt::AlignCenter);
        label_trilho2CB = new QLabel(centralWidget);
        label_trilho2CB->setObjectName(QString::fromUtf8("label_trilho2CB"));
        label_trilho2CB->setGeometry(QRect(620, 30, 250, 20));
        label_trilho2CB->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho3C = new QLabel(centralWidget);
        label_trilho3C->setObjectName(QString::fromUtf8("label_trilho3C"));
        label_trilho3C->setGeometry(QRect(870, 30, 20, 140));
        label_trilho3C->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho4CBE = new QLabel(centralWidget);
        label_trilho4CBE->setObjectName(QString::fromUtf8("label_trilho4CBE"));
        label_trilho4CBE->setGeometry(QRect(620, 150, 250, 20));
        label_trilho4CBE->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho1DA = new QLabel(centralWidget);
        label_trilho1DA->setObjectName(QString::fromUtf8("label_trilho1DA"));
        label_trilho1DA->setGeometry(QRect(190, 150, 20, 140));
        label_trilho1DA->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho4DE = new QLabel(centralWidget);
        label_trilho4DE->setObjectName(QString::fromUtf8("label_trilho4DE"));
        label_trilho4DE->setGeometry(QRect(210, 270, 250, 20));
        label_trilho4DE->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho3DBE = new QLabel(centralWidget);
        label_trilho3DBE->setObjectName(QString::fromUtf8("label_trilho3DBE"));
        label_trilho3DBE->setGeometry(QRect(460, 150, 20, 140));
        label_trilho3DBE->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho3EC = new QLabel(centralWidget);
        label_trilho3EC->setObjectName(QString::fromUtf8("label_trilho3EC"));
        label_trilho3EC->setGeometry(QRect(730, 150, 20, 140));
        label_trilho3EC->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_trilho4ED = new QLabel(centralWidget);
        label_trilho4ED->setObjectName(QString::fromUtf8("label_trilho4ED"));
        label_trilho4ED->setGeometry(QRect(480, 270, 250, 20));
        label_trilho4ED->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(186, 189, 182)}"));
        label_tremC = new QLabel(centralWidget);
        label_tremC->setObjectName(QString::fromUtf8("label_tremC"));
        label_tremC->setGeometry(QRect(600, 30, 20, 20));
        label_tremC->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(115, 210, 22)}"));
        label_tremC->setAlignment(Qt::AlignCenter);
        label_tremD = new QLabel(centralWidget);
        label_tremD->setObjectName(QString::fromUtf8("label_tremD"));
        label_tremD->setGeometry(QRect(190, 150, 20, 20));
        label_tremD->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(117, 80, 123)}"));
        label_tremD->setAlignment(Qt::AlignCenter);
        label_tremE = new QLabel(centralWidget);
        label_tremE->setObjectName(QString::fromUtf8("label_tremE"));
        label_tremE->setGeometry(QRect(460, 150, 20, 20));
        label_tremE->setStyleSheet(QString::fromUtf8("QLabel { background: rgb(252, 233, 79)}"));
        label_tremE->setAlignment(Qt::AlignCenter);
        horizontalSlider_B = new QSlider(centralWidget);
        horizontalSlider_B->setObjectName(QString::fromUtf8("horizontalSlider_B"));
        horizontalSlider_B->setGeometry(QRect(330, 360, 292, 21));
        horizontalSlider_B->setStyleSheet(QString::fromUtf8("QSlider {background: rgb(52, 101, 164)}"));
        horizontalSlider_B->setMaximum(200);
        horizontalSlider_B->setSliderPosition(100);
        horizontalSlider_B->setOrientation(Qt::Horizontal);
        horizontalSlider_C = new QSlider(centralWidget);
        horizontalSlider_C->setObjectName(QString::fromUtf8("horizontalSlider_C"));
        horizontalSlider_C->setGeometry(QRect(330, 390, 292, 21));
        horizontalSlider_C->setStyleSheet(QString::fromUtf8("QSlider {background: rgb(115, 210, 22)}"));
        horizontalSlider_C->setMaximum(200);
        horizontalSlider_C->setSliderPosition(100);
        horizontalSlider_C->setOrientation(Qt::Horizontal);
        horizontalSlider_E = new QSlider(centralWidget);
        horizontalSlider_E->setObjectName(QString::fromUtf8("horizontalSlider_E"));
        horizontalSlider_E->setGeometry(QRect(330, 450, 292, 21));
        horizontalSlider_E->setStyleSheet(QString::fromUtf8("QSlider {background: rgb(252, 233, 79)}"));
        horizontalSlider_E->setMaximum(200);
        horizontalSlider_E->setSliderPosition(100);
        horizontalSlider_E->setOrientation(Qt::Horizontal);
        horizontalSlider_D = new QSlider(centralWidget);
        horizontalSlider_D->setObjectName(QString::fromUtf8("horizontalSlider_D"));
        horizontalSlider_D->setGeometry(QRect(330, 420, 292, 21));
        horizontalSlider_D->setStyleSheet(QString::fromUtf8("QSlider {background: rgb(117, 80, 123)}"));
        horizontalSlider_D->setMaximum(200);
        horizontalSlider_D->setSliderPosition(100);
        horizontalSlider_D->setOrientation(Qt::Horizontal);
        horizontalSlider_A = new QSlider(centralWidget);
        horizontalSlider_A->setObjectName(QString::fromUtf8("horizontalSlider_A"));
        horizontalSlider_A->setGeometry(QRect(330, 330, 292, 21));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider_A->sizePolicy().hasHeightForWidth());
        horizontalSlider_A->setSizePolicy(sizePolicy);
        horizontalSlider_A->setStyleSheet(QString::fromUtf8("QSlider {background: rgb(239, 41, 41)}"));
        horizontalSlider_A->setMinimum(0);
        horizontalSlider_A->setMaximum(200);
        horizontalSlider_A->setSliderPosition(100);
        horizontalSlider_A->setOrientation(Qt::Horizontal);
        horizontalSlider_A->setTickInterval(0);
        label_A = new QLabel(centralWidget);
        label_A->setObjectName(QString::fromUtf8("label_A"));
        label_A->setGeometry(QRect(300, 332, 20, 17));
        label_B = new QLabel(centralWidget);
        label_B->setObjectName(QString::fromUtf8("label_B"));
        label_B->setGeometry(QRect(300, 362, 20, 17));
        label_C = new QLabel(centralWidget);
        label_C->setObjectName(QString::fromUtf8("label_C"));
        label_C->setGeometry(QRect(300, 392, 20, 17));
        label_D = new QLabel(centralWidget);
        label_D->setObjectName(QString::fromUtf8("label_D"));
        label_D->setGeometry(QRect(300, 422, 20, 17));
        label_E = new QLabel(centralWidget);
        label_E->setObjectName(QString::fromUtf8("label_E"));
        label_E->setGeometry(QRect(0, 0, 9, 17));
        MainWindow->setCentralWidget(centralWidget);
        label_trilho1DA->raise();
        label_trilho3DBE->raise();
        label_trilho2AB->raise();
        label_trilho4ABD->raise();
        label_trilho3AB->raise();
        label_trilho1A->raise();
        label_tremA->raise();
        pushButton->raise();
        pushButton_2->raise();
        label_trilho3BC->raise();
        label_trilho2BAC->raise();
        label_trilho4BADEC->raise();
        label_tremB->raise();
        label_trilho2CB->raise();
        label_trilho3C->raise();
        label_trilho4CBE->raise();
        label_trilho4DE->raise();
        label_trilho3EC->raise();
        label_trilho4ED->raise();
        label_tremC->raise();
        label_tremD->raise();
        label_tremE->raise();
        horizontalSlider_B->raise();
        horizontalSlider_C->raise();
        horizontalSlider_E->raise();
        horizontalSlider_D->raise();
        horizontalSlider_A->raise();
        label_A->raise();
        label_B->raise();
        label_C->raise();
        label_D->raise();
        label_E->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1034, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_tremA->setText(QApplication::translate("MainWindow", "A", nullptr));
        label_trilho2AB->setText(QString());
        label_trilho4ABD->setText(QString());
        label_trilho3AB->setText(QString());
        label_trilho1A->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Ligar", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Parar", nullptr));
        label_trilho3BC->setText(QString());
        label_trilho2BAC->setText(QString());
        label_trilho4BADEC->setText(QString());
        label_tremB->setText(QApplication::translate("MainWindow", "B", nullptr));
        label_trilho2CB->setText(QString());
        label_trilho3C->setText(QString());
        label_trilho4CBE->setText(QString());
        label_trilho1DA->setText(QString());
        label_trilho4DE->setText(QString());
        label_trilho3DBE->setText(QString());
        label_trilho3EC->setText(QString());
        label_trilho4ED->setText(QString());
        label_tremC->setText(QApplication::translate("MainWindow", "C", nullptr));
        label_tremD->setText(QApplication::translate("MainWindow", "D", nullptr));
        label_tremE->setText(QApplication::translate("MainWindow", "E", nullptr));
        label_A->setText(QApplication::translate("MainWindow", "A", nullptr));
        label_B->setText(QApplication::translate("MainWindow", "B", nullptr));
        label_C->setText(QApplication::translate("MainWindow", "C", nullptr));
        label_D->setText(QApplication::translate("MainWindow", "D", nullptr));
        label_E->setText(QApplication::translate("MainWindow", "E", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
