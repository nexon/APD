#ifndef TRANSICION_H
#define TRANSICION_H
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <qstring.h>
#include "conjuntofinal.h"

using namespace std;

class Transicion {
    protected:
        class Nodo {
            public:
                QString estado;
                QString letra;
                QString simbolo;
                ConjuntoFinal *derecha;
                Nodo *siguiente;
           };
        Nodo *inicio;
        public:
                Transicion() {inicio = 0;}
                void inserta(QString estado, QString letra, QString simbolo,ConjuntoFinal *derecha);
                void elimina(QString estado, QString letra, QString simbolo);
                ConjuntoFinal* buscarTransicion(QString estado, QString letra, QString simbolo);
                void eliminaTodo();
        
  };

#endif // TRANSICION_H
