// POJ 1852 - Ants
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
  ios_base::sync_with_stdio(false);

  int n; cin >> n; // n of test cases
  forn(i,n){
    int l; cin >> l;
    int ants; cin >> ants;

    int distMin = 0;
    int distMax = 0;

    forn(j,ants){
      int pos; cin >> pos;

      int x = min(pos, l-pos);
      int y;
      if(x == pos){
        y = l-pos;
      }else{
        y = pos;
      }

      distMin = max(distMin, x);
      distMax = max(distMax, y);
    }

    cout << distMin << " " << distMax << "\n";
  }
  // -.---..---
  return 0;
}