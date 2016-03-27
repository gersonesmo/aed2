#include "EnteroLargo.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

EnteroLargo sumaP(EnteroLargo a, EnteroLargo b){
    list<char>::reverse_iterator it1 = a.getNum().rbegin();
    list<char>::reverse_iterator it2 = b.getNum().rbegin();
    string resultado = "";
    int acarreo = 0;
    int l;
    
    if (a.getNum().size() < b.getNum().size()){
        int nCeros = b.getNum().size()-a.getNum().size();
        for (int i = 0; i < nCeros; i++) {
            a.getNum().push_front('0');
        }
    }
    else {
        int nCeros = a.getNum().size()-b.getNum().size();
        for (int i = 0; i < nCeros; i++) {
            b.getNum().push_front('0');
        }
    }
    
    for (int i = a.getNum().size()-1; i >= 0; i--) {
        l = ((int)(*it1) - '0') + ((int)(*it2) - '0') + acarreo;
        if (l > 9){
            acarreo = l / 10;
            l = l % 10;
        }
        else acarreo = 0;
        resultado = to_string(l) + resultado;
        it1++;
        it2++;
    }
    if (acarreo != 0)
        resultado = to_string(acarreo) + resultado;
    return EnteroLargo(resultado);
}

EnteroLargo multP(int n, EnteroLargo largo){
    int acarreo = 0;
    string resultado = "";
    list<char>::reverse_iterator itV = largo.getNum().rbegin();
    while (itV != largo.getNum().rend()){
        int m = (int)(*itV) - '0';
        m = (m * n) + acarreo;
        if (m > 9){
            acarreo = m / 10;
            m = m % 10;
        }
        else acarreo = 0;
        resultado = to_string(m) + resultado;
        itV++;
    }
    resultado = to_string(acarreo) + resultado;
    return EnteroLargo(resultado);
}

EnteroLargo desp (EnteroLargo largo, int d){
    for (int i = 0; i < d; i++) {
        largo.getNum().push_back('0');
    }
    return largo;
}

EnteroLargo multELDirecta(EnteroLargo n1, EnteroLargo n2){
    int i = 0;
    EnteroLargo sum = EnteroLargo("0");
    list<char>::reverse_iterator itU = n1.getNum().rbegin();
    while (itU!=n1.getNum().rend()){
            int u = (int)(*itU) - '0';
            sum = sumaP(sum, desp(multP(u,n2),i));
            itU++;
            i++;
        }
    return sum;
}


int main(void){
    int k1, k2;
    string num1, num2;
    EnteroLargo n1 = EnteroLargo("48636283");
    EnteroLargo n2 = EnteroLargo("53457984");
    EnteroLargo res = multELDirecta(n1, n2);
    res.printEL();
}

