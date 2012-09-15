#include <QtGui/QApplication>
#include "mainwindow.h"

/**
 * Main
 *
 * Archivo de ejecucion de la aplicacion.
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
