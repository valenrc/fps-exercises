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

const double MM = 5.20;
const double zero = 0.00; //=??
const double delta = 1e-8;

int zzero(double x){
  if(x < -delta){
    return -1;
  }
  return x > delta;
}

int solve(double x, vector<double>* vl){
  // binary search
  int r = int((*vl).size());
  int l = 0;
  while(l+1 < r){
    int m = ceil((l+r)/2);
    //cout << l << " " << m << " " << r << endl;
    //cout << (*vl)[m] << endl;
    if(x < (*vl)[m]){
      r = m;
    }else{
      l = m;
    }
  }
  return r;
}
int main(){
  // calcular la longitud para n cartas
  // la longitud es como maximo 5.20
  // long[n] = (long[n-1] + 1) / n+1

  vector<double> vl;
  double l = 0.0;
  vl.push_back(l);
  for(int n=1; l <= MM; n++){
    l = vl[n-1] + (1.0 / double(n+1));
    vl.push_back(l);
  }

  double x; cin >> x;

  while(x != zero){
    int res = solve(x, &vl);
    cout << res << " card(s)" << endl;
    cin >> x;
  }

  return 0;
}