// POJ 2262 - Goldbach's Conjecture
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

// Implementaciones para grafos
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

#define forn(i,n)     for(int i=0;i<n;i++)
#define fordn(i,d,n)  for(int i=d;i<n;i++)
#define forall(i, c)  for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)

#define pb push_back

void print_vi(vi& v){
    forall(i,v) cout << *i << " ";
    cout << endl;
}

const int MAX = 1000001;

int main(){
  // calculo los primos usando criba de eratostenes
  vector<bool> isprime(MAX, true);
  vector<int> primes;

  isprime[0] = isprime[1] = false;
  for(int i=2; i<MAX; i++){
    if(isprime[i]){
      for(int j=2; j*i<MAX; j++){
        isprime[j*i]= false;
      }
    }
  }

  for(int i=2; i<MAX; i++){
    if(isprime[i]){
      primes.push_back(i);
    }
  }

  int x;
  cin >> x;  // el input es un numero par > 6
  int s1 = -1, s2 = -1;
  while(x){
    for(int i=0; i<primes.size(); i++){
      if(primes[i]*2 > x) break;

      if(isprime[x - primes[i]]){
        s2 = primes[i];
        s1 = x-primes[i];
        break;
      }
    }

    if(s1 > s2){
      swap(s1, s2);
    }
    if(s1 == -1 && s2 == -1){
      cout << "Goldbach's conjecture is wrong" << endl;
    }else{
      cout << x << " = " << s1 << " + " << s2 << endl;
    }

    cin >> x;
  }

  return 0;
}