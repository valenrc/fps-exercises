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


void solve(int n){
  string s; cin >> s;
  cout << s << endl;

  if(n-1 > 0){
    n--;
    cin >> s;
    if(n-1 > 0) solve(n-1);
    cout << s << endl;
  }
}

int main(){
  int n;
  int loop = 1;
  cin >> n;

  while(n){
    cout << "SET " << loop++ << endl;
    solve(n);
    cin >> n;
  }

  return 0;
}