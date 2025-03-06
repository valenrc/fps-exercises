#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;

#define forn(i,n)     for(int i=0;i<n;i++)
#define fordn(i,d,n)  for(int i=d;i<n;i++)
#define forall(i, c) for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)

#define pb push_back

int main(){
  int n;
  cin >> n;

  int sp,h,hh;

  while(n!=-1){
    hh = 0;
    int res = 0;
    forn(i,n){
      cin >> sp; cin >> h;
      res += sp * (h-hh);
      hh = h;
    }

    cout << res << " miles" << endl  ;
    cin >> n;
  }
  return 0;
}