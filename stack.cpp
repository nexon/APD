#include <string.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "stack.h"
#include "QString"

/**
 * Stack
 *
 * Clase que implementa la estructura de datos del mismo nombre para el APD.
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */

/**
 * Metodo Agregar
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 * @param QString
 */
void Stack::agrega(QString simbolo){
     Nodo *nuevo = new Nodo();
     nuevo->simbolo = simbolo;
     nuevo->siguiente =inicio;
     inicio=nuevo;
}

/**
 * Metodo Eliminar
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
void Stack::elimina(void){
     if (inicio !=0){
                Nodo *aux=inicio;
                if (aux->siguiente) //mas de un elemento en la cola
                    inicio = inicio->siguiente;
                else
                   inicio=0;
                delete aux;

       }
}

/**
 * Metodo Obtener Tope
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */
QString Stack::obtenerTope() {
    if(inicio == 0) {
        return "VACIA";
    } else {
        return this->inicio->simbolo;
    }
}
void Stack::reset() {
    while(inicio != 0) this->elimina();
}
