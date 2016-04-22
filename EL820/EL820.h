//DyV
#ifndef _EL820_H_
#define _EL820_H_

#include "EnteroLargo.h"

using namespace std;

class EL820 {
    private:
        EnteroLargo numero[8];
        int cero1, cero2, n;
        static EnteroLargo multPorCasos (EL820 a, EnteroLargo b, int alg);
    public:
        EL820(int cero1, int cero2, string numero);
        static EnteroLargo multEL820(EL820 a, EL820 b, int alg);
};
#endif