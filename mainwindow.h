#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <apd.h>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    apd *automata;
    QStringList *tmpIzq;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void limpiarCamposTransicion();

private:
    Ui::MainWindow *ui;


private slots:
    void on_verificarPalabra_clicked();
    void on_ingresarNuevoAutomata_clicked();
    void on_editarTransicion_clicked();
    void on_tablaDeTransiciones_cellPressed(int row, int column);
    void on_opStackVacio_clicked();
    void on_opEstadoFinal_clicked();
    void on_eliminarTransicion_clicked();
    void on_agregarTransicion_clicked();
};

#endif // MAINWINDOW_H
