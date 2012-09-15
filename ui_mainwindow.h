/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jun 8 14:12:27 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *tablaDeTransiciones;
    QPushButton *verificarPalabra;
    QGroupBox *groupBox;
    QLabel *delta;
    QLabel *coma;
    QLabel *coma2;
    QLabel *label;
    QLineEdit *estado;
    QLineEdit *simbolo;
    QLineEdit *simboloStack;
    QPushButton *agregarTransicion;
    QPushButton *editarTransicion;
    QPushButton *eliminarTransicion;
    QLabel *coma2_2;
    QLabel *label_2;
    QLineEdit *simboloStackLlegada;
    QLineEdit *estadoLlegada;
    QLabel *label_3;
    QLabel *delta_2;
    QGroupBox *groupBox_3;
    QRadioButton *opEstadoFinal;
    QRadioButton *opStackVacio;
    QGroupBox *groupBox_2;
    QLabel *labelEstadoInicial;
    QLabel *labelEstadoFinal;
    QLineEdit *estadoInicial;
    QLineEdit *estadoFinal;
    QGroupBox *groupBox_4;
    QLabel *labelPalabraDeEntrada;
    QLineEdit *palabraDeEntrada;
    QPushButton *ingresarNuevoAutomata;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(644, 551);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(644, 551));
        MainWindow->setMaximumSize(QSize(644, 551));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tablaDeTransiciones = new QTableWidget(centralWidget);
        if (tablaDeTransiciones->columnCount() < 2)
            tablaDeTransiciones->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablaDeTransiciones->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablaDeTransiciones->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tablaDeTransiciones->setObjectName(QString::fromUtf8("tablaDeTransiciones"));
        tablaDeTransiciones->setGeometry(QRect(10, 230, 621, 191));
        tablaDeTransiciones->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tablaDeTransiciones->setDragDropOverwriteMode(false);
        verificarPalabra = new QPushButton(centralWidget);
        verificarPalabra->setObjectName(QString::fromUtf8("verificarPalabra"));
        verificarPalabra->setEnabled(false);
        verificarPalabra->setGeometry(QRect(380, 430, 241, 32));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 100, 621, 121));
        delta = new QLabel(groupBox);
        delta->setObjectName(QString::fromUtf8("delta"));
        delta->setGeometry(QRect(50, 40, 21, 51));
        QFont font;
        font.setPointSize(40);
        delta->setFont(font);
        coma = new QLabel(groupBox);
        coma->setObjectName(QString::fromUtf8("coma"));
        coma->setGeometry(QRect(110, 40, 16, 51));
        coma->setFont(font);
        coma2 = new QLabel(groupBox);
        coma2->setObjectName(QString::fromUtf8("coma2"));
        coma2->setGeometry(QRect(170, 40, 16, 51));
        coma2->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 40, 51, 51));
        label->setFont(font);
        estado = new QLineEdit(groupBox);
        estado->setObjectName(QString::fromUtf8("estado"));
        estado->setGeometry(QRect(70, 50, 41, 31));
        simbolo = new QLineEdit(groupBox);
        simbolo->setObjectName(QString::fromUtf8("simbolo"));
        simbolo->setGeometry(QRect(130, 50, 41, 31));
        simboloStack = new QLineEdit(groupBox);
        simboloStack->setObjectName(QString::fromUtf8("simboloStack"));
        simboloStack->setGeometry(QRect(190, 50, 41, 31));
        agregarTransicion = new QPushButton(groupBox);
        agregarTransicion->setObjectName(QString::fromUtf8("agregarTransicion"));
        agregarTransicion->setGeometry(QRect(10, 90, 171, 32));
        editarTransicion = new QPushButton(groupBox);
        editarTransicion->setObjectName(QString::fromUtf8("editarTransicion"));
        editarTransicion->setEnabled(false);
        editarTransicion->setGeometry(QRect(210, 90, 161, 32));
        eliminarTransicion = new QPushButton(groupBox);
        eliminarTransicion->setObjectName(QString::fromUtf8("eliminarTransicion"));
        eliminarTransicion->setEnabled(false);
        eliminarTransicion->setGeometry(QRect(420, 90, 161, 32));
        coma2_2 = new QLabel(groupBox);
        coma2_2->setObjectName(QString::fromUtf8("coma2_2"));
        coma2_2->setGeometry(QRect(360, 40, 20, 51));
        coma2_2->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(420, 40, 21, 51));
        label_2->setFont(font);
        simboloStackLlegada = new QLineEdit(groupBox);
        simboloStackLlegada->setObjectName(QString::fromUtf8("simboloStackLlegada"));
        simboloStackLlegada->setGeometry(QRect(370, 50, 41, 31));
        estadoLlegada = new QLineEdit(groupBox);
        estadoLlegada->setObjectName(QString::fromUtf8("estadoLlegada"));
        estadoLlegada->setGeometry(QRect(320, 50, 41, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 40, 20, 51));
        label_3->setFont(font);
        delta_2 = new QLabel(groupBox);
        delta_2->setObjectName(QString::fromUtf8("delta_2"));
        delta_2->setGeometry(QRect(20, 40, 31, 51));
        delta_2->setPixmap(QPixmap(QString::fromUtf8("delta.png")));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 0, 171, 101));
        opEstadoFinal = new QRadioButton(groupBox_3);
        opEstadoFinal->setObjectName(QString::fromUtf8("opEstadoFinal"));
        opEstadoFinal->setGeometry(QRect(20, 30, 101, 20));
        opEstadoFinal->setChecked(true);
        opStackVacio = new QRadioButton(groupBox_3);
        opStackVacio->setObjectName(QString::fromUtf8("opStackVacio"));
        opStackVacio->setGeometry(QRect(20, 60, 101, 20));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(190, 0, 221, 101));
        labelEstadoInicial = new QLabel(groupBox_2);
        labelEstadoInicial->setObjectName(QString::fromUtf8("labelEstadoInicial"));
        labelEstadoInicial->setGeometry(QRect(20, 30, 141, 21));
        QFont font1;
        font1.setPointSize(20);
        labelEstadoInicial->setFont(font1);
        labelEstadoFinal = new QLabel(groupBox_2);
        labelEstadoFinal->setObjectName(QString::fromUtf8("labelEstadoFinal"));
        labelEstadoFinal->setGeometry(QRect(20, 70, 131, 21));
        labelEstadoFinal->setFont(font1);
        estadoInicial = new QLineEdit(groupBox_2);
        estadoInicial->setObjectName(QString::fromUtf8("estadoInicial"));
        estadoInicial->setGeometry(QRect(160, 20, 41, 31));
        estadoFinal = new QLineEdit(groupBox_2);
        estadoFinal->setObjectName(QString::fromUtf8("estadoFinal"));
        estadoFinal->setGeometry(QRect(160, 60, 41, 31));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(420, 0, 211, 101));
        labelPalabraDeEntrada = new QLabel(groupBox_4);
        labelPalabraDeEntrada->setObjectName(QString::fromUtf8("labelPalabraDeEntrada"));
        labelPalabraDeEntrada->setGeometry(QRect(10, 30, 191, 16));
        labelPalabraDeEntrada->setFont(font1);
        palabraDeEntrada = new QLineEdit(groupBox_4);
        palabraDeEntrada->setObjectName(QString::fromUtf8("palabraDeEntrada"));
        palabraDeEntrada->setGeometry(QRect(10, 50, 181, 31));
        ingresarNuevoAutomata = new QPushButton(centralWidget);
        ingresarNuevoAutomata->setObjectName(QString::fromUtf8("ingresarNuevoAutomata"));
        ingresarNuevoAutomata->setEnabled(false);
        ingresarNuevoAutomata->setGeometry(QRect(10, 430, 241, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 644, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(opEstadoFinal, opStackVacio);
        QWidget::setTabOrder(opStackVacio, estadoInicial);
        QWidget::setTabOrder(estadoInicial, estadoFinal);
        QWidget::setTabOrder(estadoFinal, palabraDeEntrada);
        QWidget::setTabOrder(palabraDeEntrada, estado);
        QWidget::setTabOrder(estado, simbolo);
        QWidget::setTabOrder(simbolo, simboloStack);
        QWidget::setTabOrder(simboloStack, estadoLlegada);
        QWidget::setTabOrder(estadoLlegada, simboloStackLlegada);
        QWidget::setTabOrder(simboloStackLlegada, agregarTransicion);
        QWidget::setTabOrder(agregarTransicion, editarTransicion);
        QWidget::setTabOrder(editarTransicion, eliminarTransicion);
        QWidget::setTabOrder(eliminarTransicion, verificarPalabra);
        QWidget::setTabOrder(verificarPalabra, tablaDeTransiciones);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simulador Automata Push Down", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tablaDeTransiciones->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Lado izquierdo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tablaDeTransiciones->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Lado derecho", 0, QApplication::UnicodeUTF8));
        verificarPalabra->setText(QApplication::translate("MainWindow", "Verificar Palabra", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Agregar/Editar Transici\303\263n", 0, QApplication::UnicodeUTF8));
        delta->setText(QApplication::translate("MainWindow", "(", 0, QApplication::UnicodeUTF8));
        coma->setText(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        coma2->setText(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", ") =", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        estado->setToolTip(QApplication::translate("MainWindow", "Aqui debes ingresar el estado, un ejemplo seria qX donde X = 1, 2, 3,...n", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        simbolo->setToolTip(QApplication::translate("MainWindow", "Debes ingresar SOLO UNA letra en min\303\272scula. Epsilon se representa con la letra E (May\303\272scula)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        simboloStack->setToolTip(QApplication::translate("MainWindow", "Aqui debes ingresar solo una letra y en may\303\272sculas. Epsilon se representa con la letra E (May\303\272scula)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        agregarTransicion->setText(QApplication::translate("MainWindow", "Agregar Transicion", 0, QApplication::UnicodeUTF8));
        editarTransicion->setText(QApplication::translate("MainWindow", "Editar Transicion", 0, QApplication::UnicodeUTF8));
        eliminarTransicion->setText(QApplication::translate("MainWindow", "Eliminar Transicion", 0, QApplication::UnicodeUTF8));
        coma2_2->setText(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", ")", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        simboloStackLlegada->setToolTip(QApplication::translate("MainWindow", "Aqui deben ir los simbolos que se agregan al stack. Epsilon se representa con la letra E (May\303\272scula)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        simboloStackLlegada->setText(QString());
#ifndef QT_NO_TOOLTIP
        estadoLlegada->setToolTip(QApplication::translate("MainWindow", "Aqui debes ingresar el estado al que se llega, un ejemplo seria qX donde X = 1, 2, 3,...n", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        estadoLlegada->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "(", 0, QApplication::UnicodeUTF8));
        delta_2->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Aceptaci\303\263n del Automata:", 0, QApplication::UnicodeUTF8));
        opEstadoFinal->setText(QApplication::translate("MainWindow", "Estado final", 0, QApplication::UnicodeUTF8));
        opStackVacio->setText(QApplication::translate("MainWindow", "Stack vacio", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Estados:", 0, QApplication::UnicodeUTF8));
        labelEstadoInicial->setText(QApplication::translate("MainWindow", "Estado Inicial:", 0, QApplication::UnicodeUTF8));
        labelEstadoFinal->setText(QApplication::translate("MainWindow", "Estado Final:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        estadoInicial->setToolTip(QApplication::translate("MainWindow", "Aqui debes ingresar el estado inicial, un ejemplo seria qX donde X = 1, 2, 3,...n", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        estadoFinal->setToolTip(QApplication::translate("MainWindow", "Aqui debes ingresar el estado final, un ejemplo seria qX donde X = 1, 2, 3,...n", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Palabra a evaluar:", 0, QApplication::UnicodeUTF8));
        labelPalabraDeEntrada->setText(QApplication::translate("MainWindow", "Palabra de Entrada:", 0, QApplication::UnicodeUTF8));
        ingresarNuevoAutomata->setText(QApplication::translate("MainWindow", "Ingresar Nuevo Automata", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
