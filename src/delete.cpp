#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>

#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;

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

int change(int x, int i, int j){
    // cambia el i-esimo digito de x por j
    if(i==1) return (x/10)*10 + j; else
        if(i==2) return (x/100)*100 + x%10 + j*10; else
            if(i==3) return (x/1000)*1000 + x%100 + j*100; else
                if(i==4) return (x%1000) + j*1000;
}

int main(){
  int x = 1033;
  int j = 1;
  cout << change(x,2,j) << endl;
  return 0;
}