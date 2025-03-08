// POJ 1979 - Red and Black
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector< vector<bool> > vvb;

#define forn(i,n)     for(int i=0;i<n;i++)
#define fordn(i,d,n)  for(int i=d;i<n;i++)
#define forall(i, c) for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)

#define pb push_back

int solve(int x, int y, int rows, int col, vvb* v, vector<string>* map){

  //cout << "x="<< x << " y=" << y << endl;
  //cout << "rows=" << rows << " col=" << col << endl;

  if(x<0 || y<0) return 0;
  if(x>=rows || y>=col) return 0;
  if((*v)[x][y]) return 0;
  if((*map)[x][y] == '#') return 0;

  (*v)[x][y]=1;
  int a = solve(x+1, y, rows, col, v, map);
  int b = solve(x-1, y, rows, col, v, map);
  int c = solve(x, y+1, rows, col, v, map);
  int d = solve(x, y-1, rows, col, v, map);

  return 1 + a + b + c + d;
}

int main(){
  int col,rows;
  // map contiene `rows` strings
  // los strings en map son de longitud col

  int ix = 0; int iy = 0;
  cin >> col >> rows;
  while(col != 0 && rows != 0){
    vector<string> map;
    forn(i, rows){
      string s; cin >> s;
      map.pb(s);

      // obtener la posicion inicial
      forn(j, col){
        if(map[i][j] == '@') {
          ix = i;
          iy = j;
        }
      }
    }
    // calcular el resultado
    int res = 0;
	vvb visited(rows, vector<bool>(col, false));
    res = solve(ix, iy, rows, col, &visited, &map);

    cout << res << endl;
    cin >> col >> rows;
  }

  return 0;
}
