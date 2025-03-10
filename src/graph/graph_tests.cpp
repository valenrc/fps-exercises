// Tests para grap.h
#include "../comp.h"
#include "graph.h"

void test_dfs() {
  // Crear un grafo dirigido
  AL g(9);
  g[0].pb(ii(1, 1));
  g[0].pb(ii(2, 1));
  g[1].pb(ii(3, 1));
  g[1].pb(ii(4, 1));
  g[2].pb(ii(5, 1));
  g[2].pb(ii(6, 1));
  g[3].pb(ii(7, 1));
  g[4].pb(ii(7, 1));
  g[5].pb(ii(8, 1));
  g[6].pb(ii(8, 1));
  
  // Crear un vector de booleanos para marcar los nodos visitados
  vector<bool> visited(g.size(), false);

  // Realizar DFS desde el nodo 0
  cout << "DFS starting from node 0:" << endl;
  dfs(0, visited, g);
  cout << endl;
}

void test_bfs() {
  // Crear el mismo grafo dirigido
  AL g(9);
  g[0].pb(ii(1, 1));
  g[0].pb(ii(2, 1));
  g[1].pb(ii(3, 1));
  g[1].pb(ii(4, 1));
  g[2].pb(ii(5, 1));
  g[2].pb(ii(6, 1));
  g[3].pb(ii(7, 1));
  g[4].pb(ii(7, 1));
  g[5].pb(ii(8, 1));
  g[6].pb(ii(8, 1));
  
  // Crear un vector de distancias inicializado a -1 (INF)
  vector<int> distances(g.size(), -1);

  // Realizar BFS desde el nodo 0
  cout << "BFS starting from node 0:" << endl;
  bfs(0, distances, g);

  // Imprimir las distancias desde el nodo 0
  forn(i, distances.size()) {
    cout << "Distance to node " << i << ": " << distances[i] << endl;
  }
}

int main() {
  // Testear DFS
  test_dfs();

  // Testear BFS
  test_bfs();

  return 0;
}