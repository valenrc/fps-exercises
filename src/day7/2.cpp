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

int main(){
  // contar columnas 
  int test_cases; cin >> test_cases;

  forn(i, test_cases){
    vector<int> walls(101); // cant de walls por columna
    int nw; cin >> nw;    // num of walls
    int k; cin >> k;
    int x1,x2,y1,y2;
    int res = 0;

    forn(i, nw){
      cin >> x1 >> y1 >> x2 >> y2;

      for(int j=x1; j<=x2; j++){
        walls[j]++;

        if(walls[j] > k){
          res = max(res, walls[j]-k);
        }
      }
    }

    cout << res << endl;
  }
}