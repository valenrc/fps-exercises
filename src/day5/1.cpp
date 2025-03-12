// POJ 2253 - Frogger
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>

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

const float eps = 1e-9;

int main(){
  int n; cin >> n;
  int sce = 1;
  while(n){
    // armar el grafo con matriz de ady
    vector< vector<float> > g(n, vector<float>(n,0.0f));

    vector<ii> pares(n);

    forn(i,n){
      int x,y;
      cin >> x >> y;
      pares[i] = ii(x,y);
    }

    // llenar el grafo
    forn(i,n){
      forn(j,n){
        if(i!=j){
          // el peso i,j es la dist euclidiana entre i y j
          int x1 = pares[i].first;
          int y1 = pares[i].second;
          int x2 = pares[j].first;
          int y2 = pares[j].second;
          float d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
          g[i][j] = d;
        }
      }
    }

    // aplicar floyd warshall para buscar el camino minimax (bottleneck)
    forn(k,n){
      forn(i,n){
        forn(j,n){
          g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));
        }
      }
    }

    // buscar el camino minimax entre g[0][1]
    float minmax = g[0][1];
    cout << "Scenario #" << sce << endl;
    sce++;
    cout << "Frog Distance = ";
    printf("%.3f\n", minmax);
    cout << endl;

    cin >> n;
  }
  return 0;
}