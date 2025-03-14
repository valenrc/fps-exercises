// UVA 147 - Dollars
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>
#include <sstream>

#include<iomanip>

#include <map>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;

// Implementaciones para grafos
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

#define forn(i,n)     for(int i=0;i<n;i++)
#define fordn(i,d,n)  for(int i=d;i<n;i++)
#define forall(i, c)  for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)

#define pb push_back

void print_vi(vi& v){
    forall(i,v) cout << *i << " ";
    cout << endl;
}

const ll arrb[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000}; // cant de monedas de 5c que se necesitan para conseguir los valores de monedas disponibles

int main(){
  vector<ll> b(arrb, arrb + 11);
  vector<ll> a(6001); // cant de maneras de obtener i monedas de 5c mezclando otros billetes (incluido 5c)
  a[0] = 1;
  forn(i, 11){
    for(int j=b[i]; j<6001; j++){
      a[j] = a[j] + a[j - b[i]];
    }
  } // offline method

  double x; // es multiplo de 0.05

  cout << fixed << showpoint << setprecision(2);
  while(cin >> x && x != 0){
    // calcular x en funcion de la cantidad de monedas de 5c que representa
    int mon = (int)(x*20 + 0.5f);
    cout << setw(6) << x << setw(17) << a[mon] << endl;
  }
  return 0;
}