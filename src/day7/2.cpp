// POJ 1230 - Pass-Muraille
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>
#include <sstream>

#include <map>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define forn(i,n)     for(int i=0;i<n;i++)
#define fordn(i,d,n)  for(int i=d;i<n;i++)
#define forall(i, c)  for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)

#define pb push_back

struct Wall{
  int x1;
  int x2;
  bool deleted;
};

void printWallVector(const std::vector<Wall>& walls) {
  std::cout << "Walls:" << std::endl;
  for (size_t i = 0; i < walls.size(); ++i) {
    std::cout << "Wall " << i << ": x1=" << walls[i].x1
              << ", x2=" << walls[i].x2;
  }
}

const int MAX = 100;  // tamaño maximo del grid

bool compare_walls(const Wall* a, const Wall* b) {
  return a->x2 > b->x2;
}

int main(){
  int test_cases; cin >> test_cases;

  forn(t, test_cases){
    int n,k;
    cin >> n >> k;

    vector<Wall> walls(n);
    vector<int> cw(MAX,0); // conteo de muros por columna

    forn(j, n){
      int m1, m2; // coords y del muro
      int xa,xb;

      cin >> xa >> m1 >> xb >> m2;

      walls[j].x1 = xa;
      walls[j].x2 = xb;
      walls[j].deleted = false;
    }

    // recorrer la columna i de izq a derecha
    // contar la cant de muros que hay en la columna muros_en_i
    // borrar los muros que terminen mas a la derecha (ordenar walls por 'x2' descendente) hasta que muros_en_i <= k
    // actualizar la estructura de datos que cuenta los muros en las columnas
    
    // ESTA ESTRATEGIA NO FUNCIONA LOL
    int res = 0;

    for(int i=0; i<MAX; i++){
      // contar muros en la columna i
      int wall_count = 0;
      vector<int> wall_id;

      forn(j, n){
        if(!walls[j].deleted && walls[j].x1 <= i && walls[j].x2 >= i){
          // este muro esta en la columna i
          wall_count++;
          wall_id.push_back(j);
        }
      }

      // borrar muros si wall_count > k
      if(wall_count > k){
        vector<Wall*> col_walls; // vector de punteros a Wall

        for(int j=0; j<wall_id.size(); j++){
          int idx = wall_id[j];
          col_walls.push_back(&walls[idx]); // meto un puntero a todos los muros que esten en la columna actual
        }

        // ordenar col_walls por x2 ascendente
        sort(col_walls.begin(), col_walls.end(), compare_walls);

        // eliminar muros hasta que wall_count = k
        for(int i=0; i<col_walls.size() && wall_count > k; i++){
          col_walls[i]->deleted = true;
          res++;
        }
      }
    }
    cout << res << endl;
  }

  return 0;
}