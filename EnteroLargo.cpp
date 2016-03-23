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