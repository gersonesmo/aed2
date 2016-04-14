#include "EL820.h"
#include "EnteroLargo.h"
#include <iostream>

EL820::EL820(EnteroLargo * eLargo, int cero1, int cero2, int n){
    for (int i = 0; i < 8; i++) {
        if (i==cero1 || i==cero2){
            numero[i] = EnteroLargo("0");   
        }
        else{ 
            numero[i] = eLargo[i];
        }
    }
    this->cero1 = cero1;
    this->cero2 = cero2;
    this->n = n;
}

EL820::EL820(int cero1, int cero2, string numero){
    int n = numero.size()/8;
    this->cero1 = cero1;
    this->cero2 = cero2;
    this->n = n;
    for (int i = 0; i < 8; i++) {
        this->numero[i] = numero.substr(i*n, n);
    }
}

EnteroLargo EL820::multEL820 (EL820 a, EL820 b, int alg){
    EnteroLargo resultado = EnteroLargo("0");
    int d = 0; //desplazamiento
    for (int i = 7; i >= 0; i--) {
        if (i == b.cero1 || i == b.cero2){
            d++;
        }
        else {
            EnteroLargo mult = multPorCasos(a, b.numero[i], alg);
            mult.desp(d*a.n);
            resultado = EnteroLargo::suma(resultado,mult);
            d++;
        }
    }
    return resultado;
}

EnteroLargo EL820::multPorCasos(EL820 a, EnteroLargo b, int alg){
    EnteroLargo resultado = EnteroLargo("0");
    int d = 0;
    for (int i = 7; i >= 0; i--) {
        if (i == a.cero1 || i == a.cero2){
            d++;
        }
        else{
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
            mult.desp(d*a.n);
            resultado = EnteroLargo::suma(resultado, mult);
            d++;
        }
    }
    return resultado;
}
