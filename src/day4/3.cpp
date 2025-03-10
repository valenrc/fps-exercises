// following orders

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

void print_vc(const vector<char>& v) {
  for (vector<char>::const_iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << "";
  }
  cout << endl; // Salto de línea al final
}

void print_map_char_i(const map<char, int>& m) {
  for (map<char, int>::const_iterator it = m.begin(); it != m.end(); ++it) {
    // Imprime la clave y el valor
    cout << it->first << ": " << it->second << endl;
  }
}


void print_map_char_vc(const map<char, vector<char> >& m) {
  // Itera sobre cada elemento del map
  for (map<char, vector<char> >::const_iterator it = m.begin(); it != m.end(); ++it) {
    // Imprime la clave del map
    cout << it->first << ": ";

    // Itera sobre el vector asociado a la clave
    const vector<char>& vec = it->second;
    for (vector<char>::const_iterator v_it = vec.begin(); v_it != vec.end(); ++v_it) {
      cout << *v_it << " ";
    }

    cout << endl; // Salto de línea al finalizar cada clave
  }
}

void toposort(map<char, vector<char> >& g,
              map<char, bool>& visited,
              vector<char>& path,
              map<char,int>& in,
              int size)
{
  if(size==0){
    print_vc(path);
    return;
  }
  // buscar los nodos v con g_in(v) = 0
  for(map<char, bool>::iterator it = visited.begin(); it != visited.end(); ++it){
    //cout << it->first << " " << size << endl;
    char u = it->first;
    if(in[u] == 0 && !visited[u]){
      // borrar las aristas que salgan de v
      forn(i, g[u].size()){
        char v = g[u][i];
        in[v]--;
      }

      path.push_back(u);
      visited[u] = true;
      toposort(g, visited, path, in, size-1);

      // reestablecer para backtracking
      path.pop_back();
      visited[u] = false;
      forn(i, g[u].size()){
        char v = g[u][i];
        in[v]++;
      }
    }
  }
}


int main(){
  // input is terminated by end-of-file
  string var;    // variables
  while(getline(cin,var)){
    map<char, vector<char> > g;
    map<char, bool> visited;
    map<char, int> in;
    vector<char> path;

    // armar el grafo
    for(int i = 0; i < var.size(); i+=2){
      // añadir el nodo a la lista de adyacentes con vector vacio
      g[var[i]] = vector<char>();
      visited[var[i]] = false;
      in[var[i]] = 0;
    }

    // ahora armo las aristas con la sig linea
    string cstr;
    getline(cin,cstr);
    for(int i = 0; i < cstr.size(); i+=4){
      char a = cstr[i];
      char b = cstr[i+2];
      in[b] = in[b] + 1;
      g[a].push_back(b);
    }

    // ahora busco todos los topological sort del grafo
    // dfs + backtracking
    toposort(g, visited, path, in, g.size());
    cout << endl;
  }
  return 0;
}