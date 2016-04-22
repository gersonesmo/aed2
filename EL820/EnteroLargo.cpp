//KyO
#include "EnteroLargo.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

EnteroLargo::EnteroLargo(){
    signo = true;
}

EnteroLargo::EnteroLargo(string num){
    for (int i = 0; i < (int)num.size(); i++) {
        numero.push_back(num[i]);
    }
    signo = true;
}

EnteroLargo::EnteroLargo(string num, bool signo){
    for (int i = 0; i < (int)num.size(); i++) {
        numero.push_back(num[i]);
    }
    this->signo = signo;
}

EnteroLargo::EnteroLargo(list<char> num, bool signo){
    numero = num;
    this->signo = signo;
}

EnteroLargo::EnteroLargo(list<char> num){
    numero = num;
    this->signo = true;
}

EnteroLargo::EnteroLargo(const EnteroLargo* num){
    this->numero = num->numero;
    this->signo = num->signo;
}


void EnteroLargo::printEL(){
    while(*numero.begin()=='0') //elimina ceros a la izquierda del numero antes de imprimir
        numero.pop_front();
    
    list<char>::iterator it = numero.begin(); //añade el signo si fuera necesario
    if (!this->signo){
        cout << '-';
    }
    while (it != numero.end()){
        cout << (*it);
        it++;
    }
    cout << endl;
}
/* esta funcion iguala la longitud de 2 EL añadiendo ceros a la izquierda del mas corto,
es necesaria para el funcionamiento de algunas operaciones basadas en la longitud como compare*/
void EnteroLargo::leftpad(EnteroLargo &a, EnteroLargo &b){ 
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

//funcion que compara 2 EL, devuelve 1 si a es el mayor
//, 2 si es el menor, 0 si son iguales
int EnteroLargo::compare(EnteroLargo a, EnteroLargo b){
    if (a.numero.size() > b.numero.size()){
        return 1;
    }
    else if (a.numero.size() < b.numero.size()){
        return 2;
    }
    else {
        list<char>::iterator it1 = a.numero.begin();
        list<char>::iterator it2 = b.numero.begin();
        while (it1 != a.numero.end()){
            if ((int)(*it1)>(int)(*it2)){
                return 1;
            }
            else if ((int)(*it1)<(int)(*it2)){
                return 2;
            }
            it1++; it2++;
        }
    }
    return 0;

}
//funcion parecida a compare, solo que esta solo devuelve la posición en la que 2 EL
//se diferencian. Si no es el caso, devuelve -1
int EnteroLargo::comparaValida(EnteroLargo a, EnteroLargo b){
    int pos = 0;
    
    //se elimina ceros a la izquierda de ambos numeros para evitar que afecte a la comparación
    while(*a.numero.begin()=='0')
        a.numero.pop_front();
    while(*b.numero.begin()=='0')
        b.numero.pop_front();
    
    list<char>::iterator it1 = a.numero.begin();
    list<char>::iterator it2 = b.numero.begin();
    while (it1 != a.numero.end()){
        if ((int)(*it1)==(int)(*it2)){
            pos++;
        }
        else
            return pos;
        it1++; it2++;
    }
    return -1;
}

//simplemente se llama a suma con el signo de b cambiado
EnteroLargo EnteroLargo::resta(EnteroLargo a, EnteroLargo b){
    return suma(a,EnteroLargo(b.numero, !b.signo));
}

//suma de 2 EL, analiza si son positivos, negativos o de signos distintos
//y actua en consecuencia, restando si son signos distintos y sumando si son iguales
EnteroLargo EnteroLargo::suma(EnteroLargo a, EnteroLargo b){
    list<char> resultado;
    int acarreo = 0;
    if (a.signo == b.signo){ //negativo+negativo o positivo+positivo
        int sum;
        list<char>::reverse_iterator it1 = a.numero.rbegin();
        list<char>::reverse_iterator it2 = b.numero.rbegin();
        while (it1!= a.numero.rend() && it2!= b.numero.rend()){
            sum = (*it1 - '0') + (*it2 - '0') + acarreo;
            resultado.push_front((sum % 10) + '0');
            acarreo = sum / 10;
            it1++;
            it2++;
        }
        //si un numero es mas largo que otro, no habra llegado al final, por lo que
        //se comprueba si se ha terminado de recorrer ambos y si no, se termina
        //y se añade al resultado con el acarreo que haya
        if (it1 == a.numero.rend()){
            while (it2 != b.numero.rend()){
                sum = (*it2 - '0') + acarreo;
                resultado.push_front((sum % 10) + '0');
                acarreo = sum / 10;
                it2++;
            }
        }
        else{
            while (it1 != a.numero.rend()){
                sum = (*it1 - '0') + acarreo;
                resultado.push_front((sum % 10) + '0');
                acarreo = sum / 10;
                it1++;
            }
        }
        //si tras recorrer a y b queda un acarreo se añade al final
        if (acarreo != 0)
            resultado.push_front(acarreo + '0');
        return EnteroLargo(resultado, a.signo);
    }
    else{//distintos signos
        leftpad(a,b);
        list<char>::reverse_iterator itGrande;
        list<char>::reverse_iterator itPeq;
        list<char>::reverse_iterator endGrande;
        list<char>::reverse_iterator endPeq;
        bool signoRes;
        //se resta el mayor menos el menor, para lo cual llama a compare
        //y pone el iterador grande en el mayor y el pequeño en el menor
        switch (compare(a,b)) {
            case 1: //a mayor
                itGrande = a.numero.rbegin();
                itPeq = b.numero.rbegin();
                endGrande = a.numero.rend();
                endPeq = b.numero.rend();
                signoRes = a.signo;
                break;
            case 2: //b mayor
                itGrande = b.numero.rbegin();
                itPeq = a.numero.rbegin();
                endGrande = b.numero.rend();
                endPeq = a.numero.rend();
                signoRes = b.signo;
                break;
            case 0: //iguales
                return EnteroLargo("0",true);
                break;
        }
        int resta;
        while (itGrande!=endGrande && itPeq!=endPeq) {
            if (*itGrande>=(*itPeq+acarreo)){
                resta = (*itGrande -'0') - ((*itPeq - '0') + acarreo);
                acarreo = 0;
            }
            else {
                resta = (*itGrande - '0' + 10) - ((*itPeq - '0') + acarreo);
                acarreo = 1;
            }
            itGrande++; itPeq++;
            resultado.push_front(resta + '0');
        }
        return EnteroLargo(resultado, signoRes);
    }
}

//multiplicacion de un entero(de un digito) por un EL
EnteroLargo EnteroLargo::multUnoPorTodo(int n, EnteroLargo largo){
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
    return resultado;
}

//desplazamiento de un EL
void EnteroLargo::desp (int d){
    for (int i = 0; i < d; i++) {
        numero.push_back('0');
    }
}

EnteroLargo EnteroLargo::multELDirecta(EnteroLargo n1, EnteroLargo n2){
    int i = 0; // desplazamiento
    EnteroLargo sum = EnteroLargo("0");
    list<char>::reverse_iterator itU = n1.getNum().rbegin();
    //se va recorriendo n1 cifra a cifra y llamando a multUnoPorTodo, el resultado
    //se suma al actual con el desplazamiento correspondiente
    while (itU!=n1.getNum().rend()){
            int u = (int)(*itU) - '0';
            EnteroLargo sum2 = multUnoPorTodo(u,n2);
            sum2.desp(i);
            sum = suma(sum, sum2);
            itU++;
            i++;
        }
    sum.signo= (n1.signo==n2.signo); //a signos distintos, resultado negativo, a signos iguales, positivo
    return sum;
}

EnteroLargo EnteroLargo::multDyV (EnteroLargo n1, EnteroLargo n2){
    if ((n1.getNum().size() == 1) && (n2.getNum().size() == 1)){
        return multELDirecta(n1, n2);
    }
    else{
        leftpad(n1, n2);
        int s = n1.numero.size()/2;
        //Next devuelve un iterador en la posicion correspondiente a 
        //avanzar tantas veces como diga el segundo argumento desde el primero.
        //En este caso seria avanzar longitud/2 veces desde begin, es decir, quedaría en la mitad
        auto medion1 = next(n1.getNum().begin(), s);
        auto medion2 = next(n2.getNum().begin(), s);
        //Ahora se usa el constructor de rango a partir del cual se crean los enteros largos
        list<char> izqn1(n1.getNum().begin(), medion1), dern1(medion1, n1.getNum().end());
        list<char> izqn2(n2.getNum().begin(), medion2), dern2(medion2, n2.getNum().end());
        EnteroLargo w = EnteroLargo(izqn1);
        EnteroLargo x = EnteroLargo(dern1);
        EnteroLargo y = EnteroLargo(izqn2);
        EnteroLargo z = EnteroLargo(dern2);

        EnteroLargo m1 = multDyV(w,y);
        EnteroLargo m2 = suma(multDyV(w,z),multDyV(x,y));
        EnteroLargo m3 = multDyV(x,z);
        m1.desp(2*s);
        m2.desp(s);
        return suma(m1,suma(m2,m3));
    }
}

EnteroLargo EnteroLargo::karatsubaOfman (EnteroLargo n1, EnteroLargo n2){
    bool signoRes = (n1.signo == n2.signo); // el signo resultado es negativo si ambos son de signos distintos y positivo si no
    leftpad(n1,n2);
    int s = n1.getNum().size()/2;

    if ((n1.numero.size() == 1) && (n2.numero.size() == 1)){
        return multELDirecta(n1,n2);
    }
    else{
        leftpad(n1,n2);

        auto medion1 = next(n1.numero.begin(), n1.numero.size()/2);
        auto medion2 = next(n2.numero.begin(), n2.numero.size()/2);
        list<char> izqn1(n1.numero.begin(), medion1), dern1(medion1, n1.numero.end());
        list<char> izqn2(n2.numero.begin(), medion2), dern2(medion2, n2.numero.end());
        EnteroLargo w = EnteroLargo(izqn1, n1.signo);
        EnteroLargo x = EnteroLargo(dern1, n1.signo);
        EnteroLargo y = EnteroLargo(izqn2, n2.signo);
        EnteroLargo z = EnteroLargo(dern2, n2.signo);

        //r = u·v = 102S·w·y + 10S·[(w-x)·(z-y) + w·y + x·z] + x·z
        EnteroLargo m1 = karatsubaOfman(w,y);
        EnteroLargo m2 = karatsubaOfman(resta(w,x), resta(z,y));
        EnteroLargo m3 = karatsubaOfman(x,z);

        m2 = suma(m2, suma(m1,m3));

        m1.desp(s*2);
        m2.desp(s);

        EnteroLargo solucion = suma(m1, suma(m2, m3));

        return EnteroLargo(solucion.numero, signoRes);
    }
}
