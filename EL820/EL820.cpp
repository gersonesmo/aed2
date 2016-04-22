#include "EL820.h"
#include "EnteroLargo.h"
#include <iostream>

EL820::EL820(int cero1, int cero2, string numero){
    this->cero1 = cero1;
    this->cero2 = cero2;
    this->n = numero.size()/8;;
    int d = 0;
    for (int i = 7; i >= 0; i--) {
        this->numero[i] = numero.substr(d*n, n);
        d++;
    }
}

//alg sirve para seleccionar el algoritmo de multiplicacion que se usara
// 1 es directa, 2 es DyV y 3 es KO
EnteroLargo EL820::multEL820 (EL820 a, EL820 b, int alg){
    EnteroLargo resultado = EnteroLargo("0");
    for (int i = 0; i < 8; i++) {
        //solo multiplica si no esta en un 0 de b
        if (!(i == b.cero1 || i == b.cero2)){
            EnteroLargo mult = multPorCasos(a, b.numero[i], alg);
            mult.desp(i*a.n);
            resultado = EnteroLargo::suma(resultado,mult);
        }
    }
    return resultado;
}

EnteroLargo EL820::multPorCasos(EL820 a, EnteroLargo b, int alg){
    EnteroLargo resultado = EnteroLargo("0");
    for (int i = 0; i < 8; i++) {
        if (!(i == a.cero1 || i == a.cero2)){
            EnteroLargo mult = EnteroLargo("0");
            switch (alg){
                case 1:
                    mult = EnteroLargo::multELDirecta(a.numero[i],b);
                    break;
                case 2:
                    mult = EnteroLargo::multDyV(a.numero[i],b);
                    break;
                case 3:
                    mult = EnteroLargo::karatsubaOfman(a.numero[i],b);
                    break;
            }
            mult.desp(i*a.n);
            resultado = EnteroLargo::suma(resultado, mult);
        }
    }
    return resultado;
}
