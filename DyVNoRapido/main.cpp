//DyV
#include "EnteroLargo.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iterator>

using namespace std;

EnteroLargo sumaP(EnteroLargo a, EnteroLargo b){
    string aString = "";
    string bString = "";
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

EnteroLargo multDyV (EnteroLargo n1, EnteroLargo n2){
    if ((n1.getNum().size() == 1) && (n2.getNum().size() == 1)){
        int u = (int)(*n1.getNum().rbegin())-'0';
        return multP(u, n2);
    }
    else{
        if (n1.getNum().size() < n2.getNum().size()){
            int nCeros = n2.getNum().size()-n1.getNum().size();
            for (int i = 0; i < nCeros; i++) {
                n1.getNum().push_front('0');
            }
        }
        else {
            int nCeros = n1.getNum().size()-n2.getNum().size();
            for (int i = 0; i < nCeros; i++) {
                n2.getNum().push_front('0');
            }
        }
        auto medion1 = next(n1.getNum().begin(), n1.getNum().size()/2);
        auto medion2 = next(n2.getNum().begin(), n2.getNum().size()/2);
        list<char> izqn1(n1.getNum().begin(), medion1), dern1(medion1, n1.getNum().end());
        list<char> izqn2(n2.getNum().begin(), medion2), dern2(medion2, n2.getNum().end());
        EnteroLargo w = EnteroLargo(izqn1);
        EnteroLargo x = EnteroLargo(dern1);
        EnteroLargo y = EnteroLargo(izqn2);
        EnteroLargo z = EnteroLargo(dern2);
        return sumaP(sumaP(desp(multDyV(w, y), 2*(x.getNum().size())), 
                     desp(sumaP(multDyV(w,z),multDyV(x,y)), x.getNum().size())), 
                     multDyV(x,z));
    }
}

int main(void){
    int k1, k2;
    string num1, num2;
        EnteroLargo n1 = EnteroLargo("48636283");
        EnteroLargo n2 = EnteroLargo("53457984");
        EnteroLargo res = multDyV(n1, n2);
        res.printEL();
}