#include "apd.h"
#include <iostream>
#include <QDebug>

/**
 * APD
 *
 * Clase que implementa las funcionalidades basicas para el automata pushdown.
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */


/**
 * Constructor de clase
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 * @param QString
 * @param QString
 */
apd::apd(QString estadoInicial, QString estadoFinal) {
    this->estadoInicial = estadoInicial;
    this->estadoFinal = estadoFinal;
    this->estadoTransitorio = "0";
    this->stack = new Stack();
    this->stack->agrega("R");
    this->transiciones = new Transicion();
}

/**
 * Metodo que agrega una transicion a la lista enlazada.
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 * @param QString
 * @param QString
 * @param QString
 * @param ConjuntoFinal
 */
void apd::agregarTransicion(QString estado, QString letra, QString simbolo, ConjuntoFinal *derecha) {
    this->transiciones->inserta(estado, letra, simbolo, derecha);
}

/**
 * Metodo que devuelve el atributo transicion (getter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
Transicion *apd::transicion() {
    return this->transiciones;
}

/**
 * Metodo que que modifica el estado inicial
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void apd::modificarEstadoInicial(QString estadoInicial) {
    this->estadoInicial = estadoInicial;
}

/**
 * Metodo que obtiene el estado inicial (getter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
QString apd::obtenerEstadoInicial() {
    return this->estadoInicial;
}

/**
 * Metodo que obtiene el estado final (getter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
QString apd::obtenerEstadoFinal() {
    return this->estadoFinal;
}

/**
 * Metodo que obtiene el tope del stack (getter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
QString apd::obtenerTopeStack() {
    return stack->obtenerTope();
}

/**
 * Metodo que modifica el tope del stack (setter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void apd::modificarTopeStack(QString simbolo) {
    if(simbolo != "E"){
        int i = 0;
        while(i<simbolo.length()-1) {
            this->stack->agrega(simbolo.at(i));
            i++;
        }
        //this->stack->agrega(simbolo.at(0));
    } else {
        this->stack->elimina();
    }
}

/**
 * Metodo que modifica el estado transitorio (setter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void apd::modificarEstadoTransitorio(QString estado) {
    this->estadoTransitorio = estado;
}

/**
 * Metodo que obtiene el estado Transitorio (getter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
QString apd::obtenerEstadoTransitorio() {
    return this->estadoTransitorio;
}

/**
 * Metodo que modifica el estado final (setter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void apd::modificarEstadoFinal(QString estadoFinal) {
    this->estadoFinal = estadoFinal;
}

/**
 * Metodo que ejecuta el automata ingresado para validar la palabra dada ( por estado final)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
bool apd::solucionPorEstadoFinal() {
    //OTRA COSA
    QString palabrota = this->obtenerPalabra();
    int z = 0;
    bool flag = true;
    this->obtenerStack()->reset();
    this->obtenerStack()->agrega("R");
    while(z<palabrota.length() && flag) {
        if(this->obtenerTopeStack() != NULL) {
            Transicion *p = this->transicion();
            ConjuntoFinal *ret = p->buscarTransicion(this->obtenerEstadoTransitorio(), palabrota.at(z), this->obtenerTopeStack());
            if(ret->estado2 != "0" && ret->simbolo2 != "0") {
                this->modificarEstadoTransitorio(ret->estado2);
                this->modificarTopeStack(ret->simbolo2);
            } else {
                flag = false;
            }
        } else {
            flag = false;
        }
        z++;
    }
    if(flag) {
        if(this->obtenerEstadoTransitorio() == this->obtenerEstadoFinal()) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
/**
 * Metodo que ejecuta el automata ingresado para validar la palabra dada (stack vacio)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
bool apd::solucionPorStackVacio() {
    bool flag = true;
    int z = 0;
    QString palabrota = this->obtenerPalabra();
    this->obtenerStack()->reset();
    this->obtenerStack()->agrega("R");
    while(this->stack->obtenerTope() != "VACIA" && flag) {
        QString pal;
        if(z>palabrota.length()-1) {
            pal = "E";
        } else {
            pal = palabrota.at(z);
        }
        Transicion *p = this->transicion();
        ConjuntoFinal *ret = p->buscarTransicion(this->obtenerEstadoTransitorio(), pal, this->obtenerTopeStack());
        if(ret->estado2 != "0" && ret->simbolo2 != "0") {
            qDebug() << this->obtenerTopeStack();
            this->modificarEstadoTransitorio(ret->estado2);
            this->modificarTopeStack(ret->simbolo2);
            //qDebug() << this->obtenerTopeStack();
        } else {
            flag = false;
        }
        z++;
    }
    if(flag && (this->obtenerTopeStack() == "VACIA")) {
        return true;
    } else {
        return false;
    }
}

/**
 * Metodo que obtiene el stack (getter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
Stack* apd::obtenerStack() {
    return this->stack;
}

/**
 * Metodo que obtiene el alfabeto (getter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */

QStringList* apd::obtenerAlfabeto() {
    return this->alfabeto;
}

/**
 * Metodo que modifica el alfabeto (setter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */

void apd::modificarAlfabeto(QStringList *a) {
    this->alfabeto = a;
}

/**
 * Metodo que obtiene la Palabra (getter)
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */

QString apd::obtenerPalabra() {
    return this->palabra;
}

/**
 * Metodo que modifica la palabra
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */

void apd::modificarPalabra(QString p) {
    this->palabra = p;
}
