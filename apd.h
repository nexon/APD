#ifndef APD_H
#define APD_H

#include <QObject>
#include "stack.h"
#include "transicion.h"
#include "conjuntofinal.h"
#include "QMessageBox"

class apd : public QObject {
    public:
        apd(QString estadoInicial, QString estadoFinal);
        void agregarTransicion(QString estado, QString letra, QString simbolo, ConjuntoFinal *derecha);
        Transicion *transicion();
        void modificarEstadoInicial(QString estadoInicial);
        void modificarEstadoFinal(QString estadoFinal);
        void modificarTopeStack(QString simbolo);
        void modificarEstadoTransitorio(QString estado);
        void modificarPalabra(QString p);
        void modificarAlfabeto(QStringList *a);
        QStringList *obtenerAlfabeto();
        QString obtenerPalabra();
        QString obtenerEstadoTransitorio();
        QString obtenerEstadoInicial();
        QString obtenerEstadoFinal();
        QString obtenerTopeStack();
        bool solucionPorEstadoFinal();
        bool solucionPorStackVacio();
        Stack* obtenerStack();
    private:
        QString estadoInicial;
        QString estadoFinal;
        QString estadoTransitorio;
        QStringList *alfabeto;
        QString palabra;
        Stack   *stack;
        Transicion *transiciones;

};

#endif // APD_H
