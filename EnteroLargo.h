#ifndef _ENTERO_LARGO_H
#define _ENTERO_LARGO_H

#include <list>
#include <string>
using namespace std;

class EnteroLargo {
    private:
        list<char> numero;
    public:
        list<char> &getNum(){
            return numero;
        }
        EnteroLargo(string num);
};
#endif