// POJ 2260 - Error correction
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;

#define forn(i,n)     for(int i=0;i<n;i++)
#define fordn(i,d,n)  for(int i=d;i<n;i++)
#define forall(i, c)  for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)

#define pb push_back

int main(){
  int n;
  cin >> n;
  while(n){
    // matriz de nxn
    vvi a(n, vi(n));
    forn(i,n){
      forn(j,n){
        cin >> a[i][j];
      }
    }

    // sumar cada fila y columna
    vector<int> sf(n,0), sc(n,0);

    forn(i,n){
      forn(j,n){
        sf[i] += a[i][j];
        sc[j] += a[i][j];
      }
    }

    int fp = 0; // cant de filas impares
    int cp = 0; // cant de columnas impares
    int c = -1;
    int f = -1;

    forn(i,n){
      //cout << sf[i] << " " << sc[i] << endl;
      if(sf[i] % 2 != 0){
        fp++;
        f = i;
      }
      if(sc[i] % 2 != 0){
        cp++;
        c = i;
      }
    }

   // si no hay ninguna fila/columnna par imprimo "OK"
   if(fp == 0 && cp == 0) cout << "OK" << endl;
   // si hay exactamente una fila y columna par
   else{
     if(fp == 1 && cp == 1){
       cout << "Change bit (" << f+1 << "," << c+1 << ")" << endl;
     }else{
       cout << "Corrupt" << endl;
     }
   }

    cin >> n;
  }
  return 0;
}