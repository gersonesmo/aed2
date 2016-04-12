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

void EL820::printEL820(){
    for (int i = 0; i < 8; i++) {
        numero[i].printEL();
    }
    cout << endl;
}

EnteroLargo EL820::multDir (EL820 a, EL820 b){
    EnteroLargo resultado = EnteroLargo("0");
    int d = 0; //desplazamiento
    for (int i = 7; i >= 0; i--) {
        if (i == b.cero1 || i == b.cero2){
            d++;
        }
        else {
            EnteroLargo mult = multPeq(a, b.numero[i]);
            mult.desp(d*a.n);
            resultado = EnteroLargo::suma(resultado,mult);
            d++;
        }
    }
    return resultado;
}

EnteroLargo EL820::multPeq(EL820 a, EnteroLargo b){
    EnteroLargo resultado = EnteroLargo("0");
    int d = 0;
    for (int i = 7; i >= 0; i--) {
        if (i == a.cero1 || i == a.cero2){
            d++;
        }
        else{
            EnteroLargo mult = EnteroLargo::multELDirecta(a.numero[i],b);
            mult.desp(d*a.n);
            resultado = EnteroLargo::suma(resultado, mult);
            d++;
        }
    }
    return resultado;
}
