// POJ 1137 - The new villa
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>

#include <queue>
#include <map>

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

void print_path(vector<string>& p){
  cout << "TO-DO";
}

int croom(int u){
  return u%16;
}

void bfs(
    int u,
    vector<int>& parent,
    vector<bool>& visited,
    map<int, vector<int> >& doors,
    map<int, vector<int> >& lights
  ){
  queue<int> q; // pila de estados
  q.push(u);

  while(!q.empty()){
    int v = q.front();
    q.pop();

    // los posibles siguientes estados son:
    // 1. encender luz en cuarto r in lights[v]
    // 2. apagar  luz en cuarto  r in lights[v]
    // 3. ir a cuarto adyacente  r in doors[v]
    // sii visited[r] == false

    // lights[v] son los cuartos en los que puedo encender/apagar la luz
    int act = croom(v);  // nro de cuarto actual
    forn(i, lights[act].size()){
      int r = lights[act][i];
      int u_new = (v/16) ^ (1 << (r-1)); // encender/apagar la luz

      if(!visited[u_new]){
        visited[u_new] = true;
        parent[u_new] = v;
        q.push(u_new);
      }
    }
    // doors[v] son los cuartos a los que puedo ir
    forn(i, doors[v].size()){
      int r = doors[v][i];
      int u_new = v - act + r; // cambio el cuarto en el que estoy 

      // LA LUZ EN EL CUARTO TIENE QUE ESTAR ENCENDIDA !!! AGREGAR ESTO

      if(!visited[u_new]){
        visited[u_new] = true;
        parent[u_new] = v;
        q.push(u_new);
      }
    }
  }
}

const int maxStates = 32768; // 2^15
// State space search //
int main(){
  int n = 1;
  int r,s,d;
  cin >> r >> s >> d;
  while(r || s || d){
    vector<int> parent(maxStates, -1);
    vector<bool> visited(maxStates, false);
    // las siguientes d lineas son aristas (x,y) tales que el room x tiene una puerta al room y
    map<int, vector<int> > doors;
    forn(i,d){
      int x,y;
      cin >> x >> y;

      doors[x].pb(y);
    }
    // las siguientes s lineas son aristas (x,y) tales que hay un light switch en el room x que enciende el light del room y
    map<int, vector<int> > lights;
    forn(i,s){
      int x,y;
      cin >> x >> y;

      lights[x].pb(y);
    }
    
    // inicializo el estado inicial y final
    int u0 = 17;                    // 0000000001 0001  = (luz 1 prendida) (cuarto 1)
    int goal = (1 << (r-1+4)) + r;  // 1000000000 (r-1) = (luz r prendida) (cuarto r)
    bfs(u0, parent, visited, doors, lights);
    
    cout << "Villa #" << n++ << endl;
    if(!visited[goal]){
      cout << "The problem cannot be solved." << endl;
    }else{
      
    }
  }
  return 0;
}