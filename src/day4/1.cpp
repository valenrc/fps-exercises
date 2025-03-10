// POJ 3126 - Prime Path
// Algorithms for competitive programming: https://cp-algorithms.com/
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
    forall(i,v) cout << *i << " ";
    cout << endl;
}

bool is_prime(int x, vector<int>& primos){
    for(int i=0; i<primos.size(); i++){
        if(x%primos[i]==0) return false;
    }
    //cout << x << " ";
    return true;
}

int change(int x, int i, int j){
  // cambia el i-esimo digito de x por j
  if(i==1) return (x/10)*10 + j; else
    if(i==2) return (x/100)*100 + x%10 + j*10; else
      if(i==3) return (x/1000)*1000 + x%100 + j*100; else
        if(i==4) return (x%1000) + j*1000;
}

int main(){
  // primos[i] = true <-> i es primo
  // i = 0...9999
  vector<bool> p(10000, false);
  vector<int> primos;

  for(int i=2; i<10000; i++){
    if(is_prime(i, primos)){
      primos.push_back(i);
      p[i] = true;
    }
  }

  //print_vi(primos);
  // (x,y) in g <-> x es y pero cambiando un solo digito
  int n; cin >> n;
  forn(i,n){
    int x,y;
    cin >> x >> y;

    //cout << "dist de " << x << " " << y << endl;

    vector<int> distance(10000, -1);
    distance[x] = 0;
    // distancia[i] distancia desde x hasta y

    // bfs para encontrar el camino minimo de x a y
    queue<int> q;
    q.push(x);

    while(!q.empty()){
      int v = q.front();
      q.pop();
      if(v == y){
        //cout << v << endl;
        break;
      }
      // iterar sobre todos los vecinos
      for(int d=1; d<=4; d++){
        // d es cual digito cambio
        for(int k=0; k<=9; k++){
          if(!(d==4 && k==0)){
            int u = change(v, d, k);
            if(p[u] && distance[u] == -1){
              //cout << v << " " << u << endl;
              distance[u] = distance[v] + 1;
              q.push(u);
            }
          }
        }
      }
    }
    cout << distance[y] << endl;
  }
    //cout << x << " " << y << endl;
}
