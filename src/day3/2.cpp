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
#define forall(i, c)  for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)

#define pb push_back

void print_vi(vi& v){
  forall(i,v) cout << *i << " ";
  cout << endl;
}

int main(){
  int n;
  cin >> n;

  forn(i,n){
    string s1; // numero leido como string
    string s2;
    cin >> s1 >> s2;
    int n1 = s1.length();
    int n2 = s2.length();
    int ml = max(n1, n2);

    vector<int> v1(ml,0);
    vector<int> v2(ml,0);

    forn(j, n1){
      v1[n1-1-j] = s1[j] - '0';
    }
    forn(j, n2){
      v2[n2-1-j] = s2[j] - '0';
    }

    // iterar sobre v1 hasta que no tenga ningun leading zero


    // sumar v1 y v2 y guardar el resultado en v3

    print_vi(v1);
    print_vi(v2);

    cout << endl;
  }

  return 0;
}