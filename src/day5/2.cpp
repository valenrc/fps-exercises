// POJ 2240 - Arbitrage
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>

#include <map>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;

// Implementaciones para grafos
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define forn(i,n)     for(int i=0;i<n;i++)
#define fordn(i,d,n)  for(int i=d;i<n;i++)
#define forall(i, c)  for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)

#define pb push_back

void printmatf(const vector<vector<float> >& matrix) {
  for (vector<vector<float> >::const_iterator row = matrix.begin(); row != matrix.end(); ++row) {
      for (vector<float>::const_iterator value = row->begin(); value != row->end(); ++value) {
          cout << *value << " ";
      }
      cout << endl;
  }
}

const float minf = -1e3;
const float eps = 1e-6;

int main(){
  int caso = 1;
  int n; cin >> n;
  while(n){

    map<string,int> msi;


    forn(i,n){
      // leer los nodos
      string s; cin >> s;
      msi[s] = i;
      //cout << s << endl;
    }
    
    // g[i][j] es el exch rate de i a j
    vector< vector<float> > g(n, vector<float>(n,minf));
    // leer los exchange rates (aristas)
    int m;
    cin >> m;
    forn(i,m){
      string c1, c2;
      float rate;
      cin >> c1; cin >> rate; cin >> c2;

      int a = msi[c1];
      int b = msi[c2];

      g[a][b] = rate;
      //cout << c1 << " " << rate << " " << c2 << endl;
    }

    /*
    forn(i,n){
      g[i][i] = 0.0f;
    }
    */

    // buscar all pairs max path
    // donde la longitud del camino es el producto de los pesos
    forn(k,n){
      forn(i,n){
        forn(j,n){
          if(i!=j && i!=k && j!=k){
            g[i][j] = max(g[i][j], g[i][k] * g[k][j]);
          }
        }
      }
    }
    
    // devolver true si hay un ciclo cuya productoria es mayor a 1
    bool arb = false;
    forn(i,n){
      forn(j,n){
        if(g[i][j] * g[j][i] > 1.0f){
          if(g[i][j] != minf && g[j][i] != minf){
            
            arb = true;
            break;
          }
        }
      }
    }

    if(arb){
      cout << "Case " << caso << ": Yes" << endl;
    }else{
      cout << "Case " << caso << ": No" << endl;
    }

    //printmatf(g);
    //if(caso==2) printmatf(g);
    caso++;

    msi.clear();
    g.clear();

    cin >> n;
  }
  return 0;
}