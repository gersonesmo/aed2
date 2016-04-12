//KO
#include "EnteroLargo.h"
#include "EL820.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iterator>

using namespace std;



int main(void){
    string num1, num2;
    EnteroLargo a [] = { EnteroLargo("48636283", true), 
                         EnteroLargo("48636283", true), 
                         EnteroLargo("00000000", true), 
                         EnteroLargo("48636283", true), 
                         EnteroLargo("48636283", true), 
                         EnteroLargo("48636283", true),
                         EnteroLargo("00000000", true), 
                         EnteroLargo("48636283", true)};
                        
    EnteroLargo b [] = { EnteroLargo("53457984", true), 
                         EnteroLargo("00000000", true), 
                         EnteroLargo("53457984", true), 
                         EnteroLargo("00000000", true), 
                         EnteroLargo("53457984", true),
                         EnteroLargo("53457984", true),
                         EnteroLargo("53457984", true), 
                         EnteroLargo("53457984", true)};
    //EnteroLargo n1 = EnteroLargo("48636283", true);
    //EnteroLargo n2 = EnteroLargo("53457984", true);
    EL820 n1 = EL820(a, 6, 2, 8);
    EL820 n2 = EL820(b, 1, 3, 8);
    EnteroLargo res = EL820::multDir(n1, n2);
    res.printEL();
    cout << endl;

}
