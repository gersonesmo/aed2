//DyV
#include "EnteroLargo.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

EnteroLargo::EnteroLargo(string num){
    for (int i = 0; i < num.size(); i++) {
        numero.push_back(num[i]);
    }
}

EnteroLargo::EnteroLargo(list<char> num){
    numero.merge(num);
}

void EnteroLargo::printEL(){
    list<char>::iterator it = numero.begin();
    while (it != numero.end()){
        cout << (*it);
        it++;
    }
    cout << endl;
}