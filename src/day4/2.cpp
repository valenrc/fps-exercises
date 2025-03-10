// house of santa claus
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

void print_vi(vi& v){
    forall(i,v) cout << (*i)+1 << "";
    cout << endl;
}

void dfs(int v, int aristas, vvi& g, vi& path){
  if(aristas==8){
    print_vi(path);
    return;
  }

  forn(i, 5){
    if(g[v][i] == 1){
      //cout << "arista " << v << " " << i << endl;
      //cout << aristas << endl;
      g[v][i] = 0;  // elimino la arista y continuo con la busqueda
      g[i][v] = 0;
      path.push_back(i);
      dfs(i, aristas+1, g, path);
      path.pop_back();
      g[v][i] = 1;
      g[i][v] = 1;
    }
  }

}

int main(){
  // hacer dfs recorriendo todas las aristas
  // armar el grafo
  vvi g(5,vi(5,0));
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(i!=j) g[i][j] = 1;
    }
  }
  g[3][0]=g[0][3]=0;
  g[3][1]=g[1][3]=0;

  vi path;
  path.push_back(0);

  // hacer dfs y en vez de marcarlos como visitados, elimino la arista correspondiente
  // el id0 es el nodo 1
  dfs(0, 0, g, path);

  return 0;
}