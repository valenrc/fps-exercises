// POJ 2249 - Binomial Showdown
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

typedef long long ll;

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

// (n,k) = n! / ( k! * (n-k)! ) = (n-r-1) * (n-r-2) * ... * (n-r-r) / r * (r-1) * .... 1

int main(){
  ll n,k;
  cin>>n>>k;
  ll res;

  while(n!=0 || k!=0){
    // computar el combinatorio (n,k)
    if(k!=0){
      ll a = 1;
      ll b = 1;

      if(k > n/2){
        // (n,k) = (n,n-k)
        k = n-k;
      }

      for(int i=0; i<k; i++){
        a *= (n - i);
        b *= i+1;

        if(a%b == 0){ // optmizacion
          a = a/b;
          b = 1;
        }
      }
      res = a/b;
    }else{
      res = 1;
    }

    cout << res << endl;
    cin >> n >> k;
  }
  return 0;
}