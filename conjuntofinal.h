#ifndef CONJUNTOFINAL_H
#define CONJUNTOFINAL_H
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "qstring.h"
using namespace std;

class ConjuntoFinal {
    public:
        QString estado2;
        QString simbolo2;
    public:
         ConjuntoFinal(QString e, QString s) {
                              estado2=e;
                              simbolo2=s;
         };
};

#endif // CONJUNTOFINAL_H
