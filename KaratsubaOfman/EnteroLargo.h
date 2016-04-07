//DyV
#ifndef _ENTERO_LARGO_H
#define _ENTERO_LARGO_H

#include <list>
#include <string>
using namespace std;

class EnteroLargo {
    private:
        list<char> numero;
        bool signo;
    public:
        list<char> &getNum(){
            return numero;
        }
        EnteroLargo(string num);
        EnteroLargo(string num, bool signo);
        EnteroLargo(list<char> num);
        bool positivo(){
            return signo;
        }
        void printEL();
};
#endif