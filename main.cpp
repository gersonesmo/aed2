#include "EnteroLargo.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

EnteroLargo sumaP(EnteroLargo a, EnteroLargo b){
    string aString = "";
    string bString = "";
    list<char>::reverse_iterator it1 = a.getNum().rbegin();
    list<char>::reverse_iterator it2 = b.getNum().rbegin();
    while (it1 != a.getNum().rend()){
        aString = (*it1) + aString;
        it1++;
    }
    while (it2 != b.getNum().rend()){
        bString = (*it2) + bString;
        it2++;
    }
    string resultado = "";
    int acarreo = 0;
    int l;
    
    if (aString.size() < bString.size()){
        int nCeros = bString.size()-aString.size();
        for (int i = 0; i < nCeros; i++) {
            aString = '0'+aString;
        }
    }
    else {
        int nCeros = aString.size()-bString.size();
        for (int i = 0; i < nCeros; i++) {
            bString = '0'+ bString;
        }
    }
    
    for (int i = aString.size()-1; i >= 0; i--) {
        l = ((int)aString[i] - '0') + ((int)bString[i] - '0') + acarreo;
        if (l > 9){
            acarreo = l / 10;
            l = l % 10;
        }
        else acarreo = 0;
        resultado = to_string(l) + resultado;
    }
    if (acarreo != 0)
        resultado = to_string(acarreo) + resultado;
    cout << aString << " +  " << bString << " = " << resultado << endl;
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
    cout << n << " " << resultado << endl;
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
    /*cout << "Introduce k1 donde la longitud sea 8^k1" << endl;
    cin >> k1;
    cout << "Introduce el primer entero" << endl;
    cin >> num1;
    cout << "Introduce k2 donde la longitud sea 8^k2" << endl;
    cin >> k2;
    cout << "Introduce el segundo entero" << endl;
    cin >> num2;*/
    //if (num1.size()==pow(8,k1) && num2.size()==pow(8,k2)){
        EnteroLargo n1 = EnteroLargo("48636283");
        EnteroLargo n2 = EnteroLargo("53457984");
        EnteroLargo res = multELDirecta(n1, n2);
        
        //multP(2, n2);
    //}
    //else{
    //    cout << "Una de las 2 longitudes no es correcta" << endl;
    //}
}

