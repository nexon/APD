#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <QTableWidgetItem>
/**
 * MainWindow
 *
 * Clase que implementa la ventana
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */


/**
 * Constructor de la ventana
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 * @param QWidget
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelEstadoFinal->setVisible(false);
    ui->estadoFinal->setVisible(false);
    ui->tablaDeTransiciones->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tablaDeTransiciones->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->opStackVacio->setChecked(true);
    ui->opEstadoFinal->setChecked(false);
    ui->verificarPalabra->setEnabled(false);

    automata = 0;

    /* Seteamos los placeHolders de cada elemento de la ventana */

}

/**
 * Destructor de la ventana
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * Metodo de cambio de eventos
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 * @param QString
 */
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/**
 * Metodo que agrega una transicion cuando se presiona en el boton "Agregar Transicion"
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void MainWindow::on_agregarTransicion_clicked() {
    int row = ui->tablaDeTransiciones->rowCount();
        //hacer validacion
    if(ui->estado->text() == "" || ui->simbolo->text() == "" || ui->simboloStack->text() == "" || ui->simboloStackLlegada->text() == "" || ui->estadoLlegada->text() == "") {
        QMessageBox::warning(this, "Error Ingresando Datos", "Ingresa los datos necesarios para la transición");
    } else {
        if(ui->estado->text().at(0) == 'q' && ui->estado->text().at(1).isDigit()) {
            if(ui->simbolo->text().length() == 1 ) {
                if(ui->simboloStack->text().length() == 1) {
                    ui->tablaDeTransiciones->insertRow(row);
                    /* Haciendo valido el estado ingresado */
                    QString estado1 = ui->estado->text();
                    //estado1 = estado1.remove(' ', Qt::CaseSensitivity);
                    QString s = ui->simbolo->text();
                    QString sl = ui->simboloStackLlegada->text();
                    if(sl.at(0) == QChar('E') && sl.length()>1) {
                        QMessageBox::warning(this, "Error", "Si ingresas Epsilon, no debes ingresar ninguna letra más.");
                        ui->simboloStackLlegada->setFocus();
                    } else {
                        if(ui->simboloStackLlegada->text() != "e") sl = ui->simboloStackLlegada->text().toUpper();
                        else sl = ui->simboloStackLlegada->text();
                        if(ui->simbolo->text() == "E") {
                            QString s = ui->simbolo->text().toUpper();
                        } else {
                            QString s = ui->simbolo->text().toLower();
                        }
                        QTableWidgetItem *ladoIzquierdo = new QTableWidgetItem("("+estado1+","+s+","+ui->simboloStack->text().toUpper()+")",0);

                        QTableWidgetItem *ladoDerecho = new QTableWidgetItem("("+ui->estadoLlegada->text()+","+sl+")",0); //ui->simboloStackLlegada->text().toUpper()

                        ui->tablaDeTransiciones->setItem(row,0,ladoIzquierdo);
                        ui->tablaDeTransiciones->setItem(row,1,ladoDerecho);

                        //Preguntamos si el objeto APD esta creado;
                        if(automata != 0) {
                            ConjuntoFinal *derecha = new ConjuntoFinal(ui->estadoLlegada->text(), sl); //ui->simboloStackLlegada->text()
                            automata->agregarTransicion(ui->estado->text(), ui->simbolo->text(), ui->simboloStack->text().toUpper(), derecha);
                        } else {
                            automata = new apd(ui->estadoInicial->text(), ui->estadoFinal->text());
                            ConjuntoFinal *derecha = new ConjuntoFinal(ui->estadoLlegada->text(), sl); //ui->simboloStackLlegada->text().toUpper()
                            automata->agregarTransicion(ui->estado->text(), ui->simbolo->text().toLower(), ui->simboloStack->text().toUpper(), derecha);
                        }
                        //}
                        //LIMPIA LOS QLineEdit
                        ui->estado->setText("");
                        ui->simbolo->setText("");
                        ui->simboloStack->setText("");
                        ui->estadoLlegada->setText("");
                        ui->simboloStackLlegada->setText("");
                        ui->estado->setFocus();
                }
            }else {
                    QMessageBox::warning(this, "Error", "Solo tiene que ser un simbolo en el stack.");
                    ui->simboloStack->setFocus();
                }
            } else {
                QMessageBox::warning(this, "Error", "Solo una letra por transicion es permitida.");
                ui->simbolo->setFocus();
            }
        } else {
            QMessageBox::warning(this, "Error", "El estado DEBE comenzar con q");
            ui->estado->setFocus();
        }

    }
    ui->verificarPalabra->setEnabled(true);
}

/**
 * Metodo que elimina una transicion
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void MainWindow::on_eliminarTransicion_clicked() {
    //Buscamos la transicion y la eliminamos del automata.
    if(ui->estado->text() != "" && ui->estadoLlegada->text() != "" && ui->simbolo->text() != "" && ui->simboloStack->text() != "" && ui->simboloStackLlegada->text() != "") {
        int row = ui->tablaDeTransiciones->currentRow();
        QStringList ladoIzquierdo = ui->tablaDeTransiciones->item(row,0)->text().split(',');

        //Obtenemos el estado
        QString estadoE = ladoIzquierdo.at(0);
        estadoE = estadoE.split('(').at(1);

        //Obtenemos el simbolo a leer
        QString letraE = ladoIzquierdo.at(1);

        //Obtenemos el simbolo del stack
        QString simboloE = ladoIzquierdo.at(2);
        simboloE  = simboloE.split(')').at(0);

        //Ahora borramos de transiciones la transicion seleccionada.
        automata->transicion()->elimina(estadoE, letraE, simboloE);

        int count = ui->tablaDeTransiciones->currentRow();
        ui->tablaDeTransiciones->removeRow(count);
        if(ui->tablaDeTransiciones->rowCount() == 0) ui->eliminarTransicion->setEnabled(false);

        ui->agregarTransicion->setEnabled(true);
        ui->eliminarTransicion->setEnabled(false);
        ui->editarTransicion->setEnabled(false);
        limpiarCamposTransicion();

        if(ui->tablaDeTransiciones->rowCount() == 0) ui->verificarPalabra->setEnabled(false);
    }else {
        QMessageBox::warning(this, "Error", "Si quieres borrar una transicion, no debes borrar uno de sus elementos.");
    }
}

/**
 * Metodo que se activa cuando se selecciona el radio de Estado final
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void MainWindow::on_opEstadoFinal_clicked() {
    if(!(ui->estadoFinal->isVisible() && ui->labelEstadoFinal->isVisible())) {
        ui->estadoFinal->setVisible(true);
        ui->labelEstadoFinal->setVisible(true);
    }
}

/**
 * Metodo que se activa cuando se selecciona el radio de stack vacio
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void MainWindow::on_opStackVacio_clicked() {
    if(ui->estadoFinal->isVisible() && ui->labelEstadoFinal->isVisible()) {
        ui->estadoFinal->setVisible(false);
        ui->labelEstadoFinal->setVisible(false);
    }
    ui->opEstadoFinal->setChecked(false);
    ui->opStackVacio->setChecked(true);
}

/**
 * Metodo que se activa cuando se presiona alguna celda (fila) de la lista de transiciones.
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void MainWindow::on_tablaDeTransiciones_cellPressed(int row, int column) {
     /* Lado Izquierdo de la Transicion */
     QStringList ladoIzquierdo = ui->tablaDeTransiciones->item(row,0)->text().split(',');

     //Obtenemos el estado
     QString estado1 = ladoIzquierdo.at(0);
     estado1 = estado1.split('(').at(1);
     ui->estado->setText(estado1);

     //Obtenemos el simbolo a leer
     QString simbolo1 = ladoIzquierdo.at(1);
     ui->simbolo->setText(simbolo1);

     //Obtenemos el simbolo del stack
     QString simboloStack1 = ladoIzquierdo.at(2);
     simboloStack1 = simboloStack1.split(')').at(0);
     ui->simboloStack->setText(simboloStack1);

     /* Lado Derecho de la Transicion */
     QStringList ladoDerecho = ui->tablaDeTransiciones->item(row,1)->text().split(',');

     // Obtenemos el estado de llegada //
     QString estado2 = ladoDerecho.at(0);
     estado2 = estado2.split('(').at(1);
     ui->estadoLlegada->setText(estado2);

     // Obtenemos el simbolo que agregaremos al stack
     QString simboloStack2 =  ladoDerecho.at(1);
     simboloStack2 = simboloStack2.split(')').at(0);
     ui->simboloStackLlegada->setText(simboloStack2);


     tmpIzq = new QStringList();

     tmpIzq->append(estado1);
     tmpIzq->append(simbolo1);
     tmpIzq->append(simboloStack1);


     ui->agregarTransicion->setEnabled(false);
     ui->eliminarTransicion->setEnabled(true);
     ui->editarTransicion->setEnabled(true);
}

/**
 * Metodo que se edita la transicion seleccionada
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void MainWindow::on_editarTransicion_clicked() {
    //hace su gracia

    automata->transicion()->elimina(tmpIzq->at(0),tmpIzq->at(1),tmpIzq->at(2));

    QString estado1 = ui->estado->text();
    QString simbolo1 = ui->simbolo->text();
    QString simboloS1 = ui->simboloStack->text();
    QString estado2  = ui->estadoLlegada->text();
    QString simboloS2 = ui->simboloStackLlegada->text();

        if(ui->estado->text().at(0) == 'q' && ui->estado->text().at(1).isDigit()) {
            if(ui->simbolo->text().length() == 1 ) {
                if(ui->simboloStack->text().length() == 1) {
                    /* Haciendo valido el estado ingresado */
                    QString estado1 = ui->estado->text();
                    //estado1 = estado1.remove(' ', Qt::CaseSensitivity);
                    QString s = ui->simbolo->text();
                    QString sl = ui->simboloStackLlegada->text();
                    if(sl.at(0) == QChar('E') && sl.length()>1) {
                        QMessageBox::warning(this, "Error", "Si ingresas Epsilon, no debes ingresar ninguna letra más.");
                        ui->simboloStackLlegada->setFocus();
                    } else {
                        if(ui->simboloStackLlegada->text() != "e") sl = ui->simboloStackLlegada->text().toUpper();
                        else sl = ui->simboloStackLlegada->text();
                        if(ui->simbolo->text() == "E") {
                            QString s = ui->simbolo->text().toUpper();
                        } else {
                            QString s = ui->simbolo->text().toLower();
                        }
                        //EDICION

                        ConjuntoFinal *derecha =new ConjuntoFinal(ui->estadoLlegada->text(), sl);

                        automata->agregarTransicion(ui->estado->text(), ui->simbolo->text(), ui->simboloStack->text().toUpper(), derecha);

                        QTableWidgetItem *ladoIzquierdo = new QTableWidgetItem("("+estado1+","+s+","+ui->simboloStack->text().toUpper()+")",0);
                        QTableWidgetItem *ladoDerecho = new QTableWidgetItem("("+ui->estadoLlegada->text()+","+sl+")",0);

                        ui->tablaDeTransiciones->setItem(ui->tablaDeTransiciones->currentRow(),0,ladoIzquierdo);
                        ui->tablaDeTransiciones->setItem(ui->tablaDeTransiciones->currentRow(),1,ladoDerecho);

                        ui->agregarTransicion->setEnabled(true);
                        ui->eliminarTransicion->setEnabled(false);
                        ui->editarTransicion->setEnabled(false);
                        limpiarCamposTransicion();
                        ui->estado->setFocus();
                }
            }else {
                    QMessageBox::warning(this, "Error", "Solo tiene que ser un simbolo en el stack.");
                    ui->simboloStack->setFocus();
                }
            } else {
                QMessageBox::warning(this, "Error", "Solo una letra por transicion es permitida.");
                ui->simbolo->setFocus();
            }
        } else {
            QMessageBox::warning(this, "Error", "El estado DEBE comenzar con q");
            ui->estado->setFocus();
        }
}

/**
 * Metodo que limpia los campos de ingreso de transiciones.
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void MainWindow::limpiarCamposTransicion() {
    ui->estado->setText("");
    ui->simbolo->setText("");
    ui->simboloStack->setText("");
    ui->estadoLlegada->setText("");
    ui->simboloStackLlegada->setText("");
}
/**
 * Metodo que borra el anterior automata (y todo lo agregado) para dar paso a un nuevo automata.
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void MainWindow::on_ingresarNuevoAutomata_clicked()
{
    /* Borramos todos los campos */
    //Campos de transicion
    limpiarCamposTransicion();

    //Campos de E.I y E.F
    ui->estadoInicial->setText("");
    ui->estadoFinal->setText("");
    automata->obtenerEstadoFinal() = "";
    automata->obtenerEstadoInicial() = "";
    automata->obtenerEstadoTransitorio() = "";

    //Palabra
    ui->palabraDeEntrada->setText("");
    automata->modificarAlfabeto(new QStringList());
    automata->modificarPalabra("");

    //Stack de automata
    automata->obtenerStack()->reset();

    //transiciones de Automata
    automata->transicion()->eliminaTodo();

    //transiciones de la Interfaz
    for (int i=ui->tablaDeTransiciones->rowCount()-1; i >= 0; --i)
        ui->tablaDeTransiciones->removeRow(i);

    if(!ui->agregarTransicion->isEnabled()) ui->agregarTransicion->setEnabled(true);
    if(ui->editarTransicion->isEnabled()) ui->editarTransicion->setEnabled(false);
    if(ui->eliminarTransicion->isEnabled()) ui->eliminarTransicion->setEnabled(false);

    ui->ingresarNuevoAutomata->setEnabled(false);
    ui->verificarPalabra->setEnabled(false);
}

/**
 * Metodo que verifica la palabra dada con el automata ingresado.
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */

void MainWindow::on_verificarPalabra_clicked() {
    if(ui->estadoInicial->text() != "") {
        //le damos al automata el estado inicia/final
        automata->modificarEstadoInicial(ui->estadoInicial->text());
        automata->modificarEstadoTransitorio(automata->obtenerEstadoInicial());

        //le damos la palabra al automata
        automata->modificarPalabra(ui->palabraDeEntrada->text());

        QStringList *lista = new QStringList();

        for(int i=0;i<automata->obtenerPalabra().length();i++) {
            if(!lista->contains(automata->obtenerPalabra().at(i))) {
                lista->append(automata->obtenerPalabra().at(i));
            }
        }
        automata->modificarAlfabeto(lista);

        if(ui->opEstadoFinal->isChecked()) {
            automata->modificarPalabra(automata->obtenerPalabra().append("E"));
            automata->modificarEstadoFinal(ui->estadoFinal->text());
            if(automata->solucionPorEstadoFinal() && ui->estadoFinal->text().length()>=2) {
                QMessageBox::warning(this, "Estado Final", "Palabra reconocida por el automata dado.");
            } else {
                if(ui->estadoFinal->text().length()<2) {
                    QMessageBox::warning(this, "Estado Final", "Debes ingresar un estado final.");
                } else {
                    QMessageBox::warning(this, "Estado Final", "Palabra no reconocida por el automata dado.");
                }
            }
        } else {
            if(automata->solucionPorStackVacio()) {
                QMessageBox::warning(this, "Stack Vacio", "Palabra reconocida por el automata dado.");
            } else {
                QMessageBox::warning(this, "Stack Vacio", "Palabra no reconocida por el automata dado.");
            }
        }
        ui->ingresarNuevoAutomata->setEnabled(true);
    }
}
