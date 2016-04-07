//KO
#include "EnteroLargo.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iterator>

using namespace std;

void leftpad(EnteroLargo &a, EnteroLargo &b){
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
}

EnteroLargo sumaP(EnteroLargo a, EnteroLargo b){
    list<char>::reverse_iterator it1 = a.getNum().rbegin();
    list<char>::reverse_iterator it2 = b.getNum().rbegin();
    string resultado = "";
    int acarreo = 0;
    int l;
    
    leftpad(a,b);
    
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
//1 si mayor, 2 si menor, 3 si igual
int compare(EnteroLargo a, EnteroLargo b){
    if (a.positivo() && !b.positivo()){
        return 1;
    }
    else if (!a.positivo() && b.positivo()){
        return 2;
    }
    
    if (a.getNum().size() > b.getNum().size()){
        return 1;
    }
    else if (a.getNum().size() < b.getNum().size()){
        return 2;
    }
    else {
        list<char>::iterator it1 = a.getNum().begin();
        list<char>::iterator it2 = b.getNum().begin();
        while (it1 != a.getNum().end()){
            if ((int)(*it1)>(int)(*it2)){
                return 1;
            }
            else if ((int)(*it1)<(int)(*it2)){
                return 2;
            }
            it1++; it2++;
        }
    }
    return 3;
    
}

EnteroLargo restaP(EnteroLargo a, EnteroLargo b, bool signo){
    list<char>::reverse_iterator it1 = a.getNum().rbegin();
    list<char>::reverse_iterator it2 = b.getNum().rbegin();
    string resultado = "";
    int acarreo = 0;
    int l;
    
    leftpad(a,b);
    
    for (int i = a.getNum().size()-1; i >= 0; i--) {
        if ((int)(*it1) >= (int)(*it2)){
            l = ((int)(*it1) - '0') - ((int)(*it2) - '0' + acarreo);
            acarreo = 0;
        }
        else{
            l = ((int)(*it1) - '0' + 10) - ((int)(*it2) - '0' + acarreo);
            acarreo = 1;
        }
        resultado = to_string(l) + resultado;
        it1++; it2++;
    }
    return EnteroLargo(resultado, signo);
}

EnteroLargo resta(EnteroLargo a, EnteroLargo b){
    int comp = compare(a,b);
    if ((a.positivo()) && (b.positivo())){
        switch (comp){
            case 1:
                return restaP(a,b,true);
                break;
            case 2:
                return restaP(b,a,false);
                break;
            case 3:
                return EnteroLargo("0");
                break;
        }
    }
    else if ((!a.positivo()) && (b.positivo())){
        switch (comp){
            case 1:
                return restaP(a,b,false);
                break;
            case 2:
                return sumaP(b,a,true);
                break;
            case 3:
                return EnteroLargo("0");
                break;
    }
    else if ((a.positivo()) && (!b.positivo())){
                suma(a,b,true);
    }
    else {
        switch (comp){
            case 1:
                return restaP(a,b,false);
                break;
            case 2:
                return restaP(b,a,true);
                break;
            case 3:
                return EnteroLargo("0");
                break;
    }
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

EnteroLargo karatsubaOfman (EnteroLargo n1, EnteroLargo n2){
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
        return sumaP(sumaP(desp(karatsubaOfman(w, y), 2*(x.getNum().size())), 
                     desp(sumaP(karatsubaOfman(w,z),karatsubaOfman(x,y)), x.getNum().size())), 
                     karatsubaOfman(x,z));
    }
}

int main(void){
    int k1, k2;
    string num1, num2;
        EnteroLargo n1 = EnteroLargo("48636283");
        EnteroLargo n2 = EnteroLargo("53457984");
       // EnteroLargo res = karatsubaOfman(n1, n2);
       EnteroLargo res = restaP(n2,n1);
        res.printEL();
}