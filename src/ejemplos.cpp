// Hangover POJ 1003

#include "comp.h"

int main(){
  vi v(5,1); // 5 elementos inicializados a 1

  forall(i,v) // iterar sobre un vector de enteros
    cout << *i << " ";
  cout << endl;

  forn(i,5){    // for(int i=0;i<5;i++)
    v[i] = i;
  }

  print_vi(v);  // util para debugear

  vvi vv(5,vi(5,1)); // matriz de 5x5 inicializada a 1
  vvi vv2;           // matriz vacia


  return 0;
}