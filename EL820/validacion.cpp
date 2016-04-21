//KO
#include "EnteroLargo.h"
#include "EL820.h"
#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
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

int main(void){
    string num1, num2;
    bool fin;
    char control;

    EnteroLargo n1;
    EnteroLargo n2;


    while (!fin){
        srand(time(NULL));
        int pot;
        cin >> num1 >> num2;
        //cout <<"num1 = " << num1 << endl << "num2 = " << num2 << endl;
        n1 = EnteroLargo(num1);
        n2 = EnteroLargo(num2);
        EL820 n3 = EL820(I,J,num1);
        EL820 n4 = EL820(K,L,num2);
        if (validar(n1,n2)){
            EnteroLargo arrayEL[6];
            
            arrayEL[0] = EnteroLargo::multELDirecta(n1,n2);
            //cout << "Resultado con multiplicacion directa: " << endl;
            arrayEL[0].printEL();
            arrayEL[1] = EnteroLargo::multDyV(n1,n2);
            //cout << "Resultado con algoritmo \"divide y vencerás\": " << endl;
            arrayEL[1].printEL();
            arrayEL[2] = EnteroLargo::karatsubaOfman(n1,n2);
            //cout << "Resultado con algoritmo de Karatsuba-Ofman: " << endl;
            arrayEL[2].printEL();
            //cout << "Resultado con EL820 directo: " << endl;
            arrayEL[3] = EL820::multEL820(n3,n4,1);
            arrayEL[3].printEL();
            //cout << "Resultado con EL820 \"divide y vencerás\": " << endl;
            arrayEL[4] = EL820::multEL820(n3,n4,2);
            arrayEL[4].printEL();
            //cout << "Resultado con EL820 Karatsuba-Ofman: " << endl;
            arrayEL[5] = EL820::multEL820(n3,n4,3);
            arrayEL[5].printEL();
            
            int validez;
            
            for (int i=0; i < 5; i++){
                for (int j = i; j < 5; j++) {
                    validez = EnteroLargo::comparaValida(arrayEL[i],arrayEL[i+1]);
                    if (validez!=-1){
                        cout << "Los resultados " << i+1 << " y " << j+2 << " difieren en la posicion: ";
                        cout << validez << endl;
                    }
                }
            }
            
                    
        }
        else{
            cout << "La longitud de uno de los numeros no es una potencia de 2 mayor que 8." << endl;
        }
        cout << "¿Desea salir? [S/N] ";
        cin >> control;
        fin = control=='s' || control=='S';
    }
}
