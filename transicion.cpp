#include "ConjuntoFinal.h"
#include "transicion.h"
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h> 
#include <QString.h>

/**
 * Transicion
 *
 * Clase que implementa las transiciones en una lista enlazada (Estructura de datos).
 *
 * @author Nicole Millalaf S.
 * @author Inti Romero M.
 * @author Alberto Lagos T.
 */


void Transicion::inserta(QString estado, QString letra, QString simbolo, ConjuntoFinal *derecha){
     Nodo *nuevo = new Nodo();
     nuevo->estado=estado;
     nuevo->letra=letra;
     nuevo->simbolo=simbolo;
     nuevo->derecha=derecha;
     nuevo->siguiente=0;
     if (inicio ==0){//no existe la lista aun
        inicio = nuevo;
    }else{//hay mas de un elemento en la lista
          Nodo* aux=inicio;
          while(aux!=0 && aux->estado< nuevo->estado){//aux se mueve en la lista buscando un lugar de acuerdo al estado 
                       aux=aux->siguiente;
          }
          if(aux!=0 && aux->estado==nuevo->estado){ //los estados son iguales
                    /*se movera en la lista de acuerdo a la letra, para insertar ordenadamente*/
                   while(aux->siguiente!=0 && (aux->siguiente)->estado==nuevo->estado && aux->letra <= nuevo->letra){
                               aux=aux->siguiente;
                   }
                   Nodo* aux1 =inicio;
                if(aux1!=aux){//no estamos al inicio de la lista
                    while(aux1!=0 && aux1->siguiente != aux){
                                  aux1=aux1->siguiente;
                    }//encuentra posible posicion
                    if(nuevo->letra < aux->letra){ //verifica letra
                                    nuevo->siguiente=aux;
                                    aux1->siguiente=nuevo;
                    }else{//aux->siguiente apunta donde debe ir "nuevo"
                          if(aux->siguiente==0){//al final de la lista
                                 aux->siguiente=nuevo;
                          }else{//al medio de la lista
                              Nodo* p=(aux->siguiente);
                              aux->siguiente=nuevo;
                              nuevo->siguiente=p;
                          }
                    }
                }else{//estamos al inicio de la lista
                      if(nuevo->letra > aux->letra){//nuevo se agrega después del 1er elemento de la lista
                           nuevo->siguiente=aux->siguiente;
                           aux->siguiente=nuevo;
                      }else{ //nuevo se agrega al inicio de la lista
                           nuevo->siguiente=aux;
                           inicio=nuevo;
                            
                      }
                      
                }
                
          }else{// los estados no son iguales
                Nodo* aux1 =inicio;
                while(aux1->siguiente!=0 && aux1->siguiente != aux){
                              aux1=aux1->siguiente;
                }
                nuevo->siguiente=aux;
                aux1->siguiente=nuevo;
          }   
    }
}

void Transicion::elimina(QString estado, QString letra, QString simbolo){
     Nodo *prev = inicio;
     Nodo *aux = inicio->siguiente;
                     while(aux!=0 && estado != prev->estado){
                         prev=aux;
                         aux = aux->siguiente;
                     }
                     if (aux!=0){//encontró estado
                            while((prev->siguiente !=0)&&(prev->letra != letra)){
                                prev=prev->siguiente;
                            }
                            /*if(prev->siguiente!=0){ //Encontró la letra
                                if(prev->estado!=estado){ //Encontró la letra pero en otra transición
                                    //prev=0;
                                }
                            }else{ //legó al final de la lista
                                if(prev->letra!=letra){ //la letra no estaba en la lista
                                    //prev=0;
                                }else{ // la letra está al final de la lista
                                    if(prev->estado!=estado){ //la letra está pero en otra transición
                                        //prev=0;
                                    }
                                }
                            }*/
                          if(prev!=0){ //encontró letra
                            while((prev->siguiente !=0)&&(prev->simbolo != simbolo)){
                                prev=prev->siguiente;
                            }
                          }
                            /*if(prev->siguiente!=0){ //Encontro el simbolo
                                if(prev->estado!=estado){ //Encontró el simbolo pero en otra transición
                                    //prev=0;
                                }else{//posicion del simbolo coincide con estadoA
                                    if(prev->letra!=letra){ // posicion del simbolo no coincide con letra
                                        //prev=0;
                                    }
                                }
                            }else{ //llegó al final de la lista
                                if(prev->letra!=letra){ //simbolo no estaba en la lista
                                   // prev=0;
                                }else{ // la letra está al final de la lista
                                    if(prev->estado!=estado){ //la letra está pero en otra transición
                                       // prev=0;
                                    }
                                }
                            }
                          }*/
                          
                    }else{//final de la lista
                          if(estado==prev->estado){//si coinciden los estados
                                while((prev->siguiente !=0)&&(prev->letra != letra)){//busca letra
                                    prev=prev->siguiente;
                                }
                             /*   if(prev->siguiente!=0){ //Encontró la letra
                                    if(prev->estado!=estado){ //Encontró la letra pero en otra transición
                                        //prev=0;
                                    }
                                }else{ //legó al final de la lista
                                    if(prev->letra!=letra){ //la letra no estaba en la lista
                                        //prev=0;
                                    }else{ // la letra está al final de la lista
                                        if(prev->estado!=estado){ //la letra está pero en otra transición
                                           // prev=0;
                                        }
                                    }
                                }*/    
                                 if(prev!=0){//se encontró letra y simbolo
                                        while((prev->siguiente !=0)&&(prev->simbolo != simbolo)){
                                            prev=prev->siguiente;
                                        }
                                        /*if(prev->siguiente!=0){ //Encontro el simbolo
                                            if(prev->estado!=estado){ //Encontró el simbolo pero en otra transición
                                               // prev=0;
                                            }else{//posicion del simbolo coincide con estadoA
                                                if(prev->letra!=letra){ // posicion del simbolo no coincide con letra
                                                   // prev=0;
                                                }
                                            }
                                        }else{ //llegó al final de la lista
                                            if(prev->letra!=letra){ //simbolo no estaba en la lista
                                               // prev=0;
                                            }else{ // la letra está al final de la lista
                                                if(prev->estado!=estado){ //la letra está pero en otra transición
                                                   // prev=0;
                                                }
                                            }
                                        }*/
                                 }
                          }
                    }
           if(prev==inicio){//se quiere eliminar el principio de la lista
              Nodo* p =prev;
              inicio = inicio->siguiente;
              delete p;
           }else{
                    Nodo* ant=inicio;
                    while(ant!=0 && ant->siguiente!=prev){
                          ant=ant->siguiente;
                    }
                    Nodo* p=prev;
                    ant->siguiente = prev->siguiente;
                    delete p;
           }           
}
void Transicion:: eliminaTodo(){
       while (inicio !=0){//mientras existan elementos
                Nodo *aux=inicio;
                if (aux->siguiente) //mas de un elemento en la cola
                    inicio = inicio->siguiente;
                else
                   inicio=0;
                delete aux;

       }
}

ConjuntoFinal* Transicion:: buscarTransicion(QString estado, QString letra, QString simbolo){
     Nodo *prev = inicio;
     Nodo *aux = inicio->siguiente;
     while(aux!=0 && estado != prev->estado){
         prev=aux;
         aux = aux->siguiente;
     }
     if (aux!=0){//encontró estado
            while((prev->siguiente !=0)&&(prev->letra != letra)){
                prev=prev->siguiente;
            }
            if(prev->siguiente!=0){ //Encontró la letra
                if(prev->estado!=estado){ //Encontró la letra pero en otra transición
                    prev=0;
                }/*else{// es el mismo estado, verificar simbolo
                      if(prev->simbolo!=simbolo){
                            prev=0;
                      }         
                }*/
                
            }else{ //legó al final de la lista
                if(prev->letra!=letra){ //la letra no estaba en la lista
                    prev=0;
                }else{ // la letra está al final de la lista
                    if(prev->estado!=estado){ //la letra está pero en otra transición
                        prev=0;
                    }
                }
            }
          if(prev!=0){
            while((prev->siguiente !=0)&&(prev->simbolo != simbolo)){
                prev=prev->siguiente;
            }
            if(prev->siguiente!=0){ //Encontro el simbolo
                if(prev->estado!=estado){ //Encontró el simbolo pero en otra transición
                    prev=0;
                }else{//posicion del simbolo coincide con estadoA
                    if(prev->letra!=letra){ // posicion del simbolo no coincide con letra
                        prev=0;
                    }
                }
            }else{ //llegó al final de la lista
                if(prev->letra!=letra){ //simbolo no estaba en la lista
                    prev=0;
                }else{
                     // la letra está al final de la lista
                    if(prev->estado!=estado){ //la letra está pero en otra transición
                        prev=0;
                    }else{// es el mismo estado y letra, verificar simbolo
                          
                          if(prev->simbolo!=simbolo){
                               //cout << "aaaa\n";
                                prev=0;
                          }
                    }
                }
            }
          }
    }else{//final de la lista
          if(estado==prev->estado){
                while((prev->siguiente !=0)&&(prev->letra != letra)){
                    prev=prev->siguiente;
                }
                if(prev->siguiente!=0){ //Encontró la letra
                    if(prev->estado!=estado){ //Encontró la letra pero en otra transición
                        prev=0;
                    }
                }else{ //legó al final de la lista
                    if(prev->letra!=letra){ //la letra no estaba en la lista
                        prev=0;
                    }else{ // la letra está al final de la lista
                        if(prev->estado!=estado){ //la letra está pero en otra transición
                            prev=0;
                        }
                    }
                }    
                 if(prev!=0){
                        while((prev->siguiente !=0)&&(prev->simbolo != simbolo)){
                            prev=prev->siguiente;
                        }
                        if(prev->siguiente!=0){ //Encontro el simbolo
                            if(prev->estado!=estado){ //Encontró el simbolo pero en otra transición
                                prev=0;
                            }else{//posicion del simbolo coincide con estadoA
                                if(prev->letra!=letra){ // posicion del simbolo no coincide con letra
                                    prev=0;
                                }
                            }
                        }else{ //llegó al final de la lista
                            if(prev->letra!=letra){ //simbolo no estaba en la lista
                                prev=0;
                            }else{ // la letra está al final de la lista
                                if(prev->estado!=estado){ //la letra está pero en otra transición
                                    prev=0;
                                }
                            }
                        }
                 }
          }else{
                prev=0;
          }
    }
    if(prev!=0){// entonces la transicion si existe en la lista
         ConjuntoFinal *a=prev->derecha;
         return a;
    }else{//la transicion buscada no está en la lista
          ConjuntoFinal *c= new ConjuntoFinal("0","0");
          return c;
    }
}
