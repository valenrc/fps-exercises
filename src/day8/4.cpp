// POJ 1306 - Combinations
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>
#include <sstream>

#include<iomanip>

#include <map>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;

typedef unsigned long ull;

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

const int MAX = 110; // n <= 100

int main(){
  vector< vector<ull> > c(MAX, vector<ull>(MAX, 0)); // c[n][m] = nCm

  forn(i,MAX) c[i][0] = 1; // nC0 = 1

  // (n,m) = (n-i, m) + (n-i, m-1)
  for(int i=1; i<MAX; i++){
    for(int j=1; j<MAX; j++){
      c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
  }

  int n,k;
  cin>>n>>k;
  while(n!=0 || k!=0){
    // 100 things taken 6 at a time is 1192052400 exactly.
    cout << n << " things taken " << k << " at a time is " << c[n][k] << " exactly." << endl;
    cin >> n >> k;
  }
  return 0;
}