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
        bool positivo(){
            return signo;
        }
        EnteroLargo();
        EnteroLargo(string num);
        EnteroLargo(string num, bool signo);
        EnteroLargo(list<char> num, bool signo);
        EnteroLargo(list<char> num);
        EnteroLargo(const EnteroLargo* num);
        static void leftpad(EnteroLargo &a, EnteroLargo &b);
        static int compare(EnteroLargo a, EnteroLargo b);
        static int comparaValida(EnteroLargo a, EnteroLargo b);
        static EnteroLargo resta(EnteroLargo a, EnteroLargo b);
        static EnteroLargo suma(EnteroLargo a, EnteroLargo b);
        void desp (int d);
        static EnteroLargo multUnoPorTodo(int n, EnteroLargo largo);
        static EnteroLargo multELDirecta(EnteroLargo n1, EnteroLargo n2);
        static EnteroLargo multDyV (EnteroLargo n1, EnteroLargo n2);
        static EnteroLargo karatsubaOfman(EnteroLargo n1, EnteroLargo n2);

        void printEL();
};
#endif
