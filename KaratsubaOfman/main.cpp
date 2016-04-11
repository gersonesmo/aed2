//KO
#include "EnteroLargo.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iterator>

using namespace std;



int main(void){
    string num1, num2;

    EnteroLargo n1 = EnteroLargo("48636283", true);
    EnteroLargo n2 = EnteroLargo("53457984", true);

    EnteroLargo res = EnteroLargo::karatsubaOfman(n1, n2);
    res.printEL();

}
