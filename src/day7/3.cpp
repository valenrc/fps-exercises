// POJ 1328 - Radar Installation
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

typedef pair<double, double> pdd;

#define forn(i,n)     for(int i=0;i<n;i++)
#define fordn(i,d,n)  for(int i=d;i<n;i++)
#define forall(i, c)  for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)

#define pb push_back

void print_vdd(vector< pair<double, double> >& v) {
  for (vector< pair<double, double> >::iterator i = v.begin(); i != v.end(); ++i) {
      cout << "(" << i->first << ", " << i->second << ") ";
  }
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);

  int casen = 1;
  while(1){
    int n,d;
    cin >> n >> d;

    if(n == 0 && d == 0) break;

    vector<pdd> intervalo;
    bool f = true;

    forn(i, n){
      int x,y;
      cin >> x >> y;

      if(y > d){
        f = false;
      }else{
        double h = sqrt(static_cast<double>(d*d - y*y));
        double l = x-h;
        double r = x+h;
        intervalo.pb(make_pair(r,l));
      }
    }

    if(!f){
      cout << "Case " << casen << ": -1" << endl;
    }else{
      // ordenar por el extremo derecho (asc)
      sort(intervalo.begin(), intervalo.end());

      double radar = -1e100;
      int res = 0;

      forn(i, (int)intervalo.size()){
        double r = intervalo[i].first;
        double l = intervalo[i].second;

        if(l > radar){ // el radar esta fuera del rango de la isla
          radar = r;
          res++;
        }
      }
      cout << "Case " << casen << ": " << res << endl;
    }

    casen++;
  }
  

  return 0;
}