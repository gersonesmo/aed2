//KO
#include "EnteroLargo.h"
#include "EL820.h"
#include <iostream>
#include <string>
#include <math.h>
#include <sys/time.h>
#include <iterator>
#include <cstdlib>

using namespace std;

const int I = 6;
const int J = 2;
const int K = 1;
const int L = 3;

string genera(int n){
    int randNum;
    string generado = "";
    for (int i = 0; i < n; i++) {
        randNum = rand() % 10;
        while ((i==0) && randNum==0){
            randNum = rand() % 10;
        }
        generado = generado + to_string(randNum);
    }
    return generado;
}

int main(int argc, char const *argv[]) {
  string n1, n2;
  if (argc != 3) {
    cout << "Uso: experimenta <inicio> <fin>" << endl;
    exit(1);
  }
  else{
    cout << "Entrada, Directa, DyV, Karatsuba, EL820Directa, EL820DyV, EL820Karatsuba" << endl;
    int inicio = atoi(argv[1]);
    int fin = atoi(argv[2]);
    struct timeval ti, tf;
    double tiempo;
    for (int i = inicio; i < fin; i*=2) {
      n1 = genera(i);
      n2 = genera(i);
      EnteroLargo a = EnteroLargo(n1, true);
      EnteroLargo b = EnteroLargo(n2, true);
      EL820 c = EL820(I, J, n1);
      EL820 d = EL820(K, L, n2);
      cout << i << ", ";
      gettimeofday(&ti, NULL);
      EnteroLargo::multELDirecta(a,b);
      gettimeofday(&tf, NULL);
      tiempo = (tf.tv_sec - ti.tv_sec) + (tf.tv_usec - ti.tv_usec)/1000000.0;
      cout << tiempo << ", ";
      gettimeofday(&ti, NULL);
      EnteroLargo::multDyV(a,b);
      gettimeofday(&tf, NULL);
      tiempo = (tf.tv_sec - ti.tv_sec) + (tf.tv_usec - ti.tv_usec)/1000000.0;
      cout << tiempo << ", ";
      gettimeofday(&ti, NULL);
      EnteroLargo::karatsubaOfman(a, b);
      gettimeofday(&tf, NULL);
      tiempo = (tf.tv_sec - ti.tv_sec) + (tf.tv_usec - ti.tv_usec)/1000000.0;
      cout << tiempo << ", ";
      gettimeofday(&ti, NULL);
      EL820::multEL820(c,d,1);
      gettimeofday(&tf, NULL);
      tiempo = (tf.tv_sec - ti.tv_sec) + (tf.tv_usec - ti.tv_usec)/1000000.0;
      cout << tiempo << ", ";
      gettimeofday(&ti, NULL);
      EL820::multEL820(c,d,1);
      gettimeofday(&tf, NULL);
      tiempo = (tf.tv_sec - ti.tv_sec) + (tf.tv_usec - ti.tv_usec)/1000000.0;
      cout << tiempo << ", ";
      gettimeofday(&ti, NULL);
      EL820::multEL820(c,d,1);
      gettimeofday(&tf, NULL);
      tiempo = (tf.tv_sec - ti.tv_sec) + (tf.tv_usec - ti.tv_usec)/1000000.0;
      cout << tiempo << endl;

    }
  }
  return 0;
}
