#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <QString>

using namespace std;

class Stack {
    protected:
       class Nodo{
             public:
                QString simbolo;
                Nodo *siguiente;
       };

       Nodo * inicio;
     public:
        Stack(){inicio=0;}
        QString obtenerTope();
        void agrega(QString simbolo);
        void elimina(void);
        void reset();
};

#endif // STACK_H
