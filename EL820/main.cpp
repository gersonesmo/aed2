//KO
#include "EnteroLargo.h"
#include "EL820.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iterator>

using namespace std;

const int I = 6;
const int J = 2;
const int K = 1;
const int L = 3;

bool validar(EnteroLargo a, EnteroLargo b){
    bool cond1 = (a.getNum().size() != 0) && ((a.getNum().size() & (a.getNum().size() - 1)) == 0);
    bool cond2 = (b.getNum().size() != 0) && ((b.getNum().size() & (b.getNum().size() - 1)) == 0);
    return cond1 && cond2 && (a.getNum().size()>=8) && (b.getNum().size()>=8);
}

string genera(int n){
    int randNum;
    for (int i = 0; i < n; i++) {
        randNum = rand()%(9-0 + 1);
    }
}

int main(void){
    string num1, num2;
    bool fin;
    char control;
    
    EnteroLargo n1;
    EnteroLargo n2;
    
    
    while (!fin){
        cin >> num1 >> num2;
        cout <<"num1 = " << num1 << endl << "num2 = " << num2 << endl;
        n1 = EnteroLargo(num1);
        n2 = EnteroLargo(num2);
        EL820 n3 = EL820(I,J,num1);
        EL820 n4 = EL820(K,L,num2);
        if (validar(n1,n2)){
            EnteroLargo res1 = EnteroLargo::multELDirecta(n1,n2);
            cout << "Resultado con multiplicacion directa:" << endl;
            res1.printEL();
            res1 = EnteroLargo::multDyV(n1,n2);
            cout << "Resultado con algoritmo \"divide y vencerás\"" << endl;
            res1.printEL();
            res1 = EnteroLargo::karatsubaOfman(n1,n2);
            cout << "Resultado con algoritmo de Karatsuba-Ofman" << endl;
            res1.printEL();
            cout << "Resultado con EL820 directo: " << endl;
            res1 = EL820::multEL820(n3,n4,1);
            res1.printEL();
            cout << "Resultado con EL820 divide y venceras: " << endl;
            res1 = EL820::multEL820(n3,n4,2);
            res1.printEL();
            cout << "Resultado con EL820 Karatsuba-Ofman: " << endl;
            res1 = EL820::multEL820(n3,n4,3);
            res1.printEL();
            
        }
        else{
            cout << "La longitud de uno de los numeros no es una potencia de 2 mayor que 8." << endl;
        }
        cout << "¿Desea salir? [S/N] ";
        cin >> control;
        fin = control=='s' || control=='S';
    }
    //EL820 n3 = EL820(a, I, J, 8);
    //EL820 n4 = EL820(b, K, L, 8);
    //EnteroLargo res2 = EL820::multDir(n3, n4);
}
