// POJ 2661 - Factstone Benchmark
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>

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

const int bits0 = 4; // 1960
int main(){
  int y; cin >> y;
  while(y){
    int yy = y - 1960;
    // factstone rating: N tal que N! es el mayor factorial que puedo representar con K bits (unsigned)
    // K = cant de bits en el año Y = 2^(2+((Y-1960)/10))
    // el maximo entero que puedo representar es 2^K - 1
    // calcular n! mediante log2 i (hasta que sea mayor que K)
    long k = pow(2, 2 + (ceil((y-1960)/10)));

    double i = 1;
    double n = log2(i);
    while(n <= k){
      i++;
      n += log2(i);
    }
    cout << i-1  << endl;
    cin >> y;
  }
  return 0;
}
