//DyV
#ifndef _EL820_H_
#define _EL820_H_

#include "EnteroLargo.h"

using namespace std;

class EL820 {
    private:
        EnteroLargo numero[8];
        int cero1, cero2, n;
        static EnteroLargo multPeq (EL820 a, EnteroLargo b);
    public:
        EL820(EnteroLargo * eLargo, int cero1, int cero2, int n);
        static EnteroLargo multDir (EL820 a, EL820 b);
        void printEL820();
};
#endif