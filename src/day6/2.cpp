// POJ 2573 - Bridge
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

#define forn(i,n)     for(int i=0;i<n;i++)
#define fordn(i,d,n)  for(int i=d;i<n;i++)
#define forall(i, c)  for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)

#define pb push_back

void print_vi(vi& v){
  forall(i,v) cout << *i << " ";
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  int n;  cin >> n;
  vector<int> v;
  int faster = 0;
  int slower = n-1;

  ostringstream output;

  int time = 0;

  forn(i,n){
    int t; cin>>t;  // crossing time for each one
    v.pb(t);
  }
  //  cout << "n: " << n << endl;
  //print_vi(v);

  sort(v.begin(),v.end()); // ordenar ascendente
  while(n > 3){
    int A = v[faster];
    int B = v[faster+1];
    int a = v[slower];
    int b = v[slower-1];

    // 2A+a+b la persona mas rapida ayuda a los mas lentos a cruzar
    // 2B+A+a los dos mas rapidos ayudan a los dos mas lentos sucesivamente
    if(2*A+a+b < 2*B+A+a){
      // cruza A y a, vuelve A, cruza A y b, vuelve A
      output << A << " " << a << endl;
      output << A << endl;
      output << A << " " << b << endl;
      output << A << endl;
      time += 2*A+a+b;
      n-=2;
      slower-=2;
    }else{
      // cruzan B y A, vuelve A, cruzan a y b, vuelve B
      output << A << " " << B << endl;
      output << A << endl;
      output << b << " " << a << endl;
      output << B << endl;
      time += 2*B+A+a;
      n-=2;
      slower-=2;
    }
  }

  if(n ==3){
    // cruzan A y B, vuelve A, cruzan A y a
    output << v[faster] << " " << v[faster+1] << endl;
    output << v[faster] << endl;
    output << v[faster] << " " << v[slower] << endl;
    time += v[faster]+v[faster+1]+v[slower];
  }

  if(n == 1){
    time += v[faster];
    output << v[faster] << endl;
  }
  if(n == 2){
    time += v[slower];
    output << v[faster] << " " << v[slower] << endl;
  }
  cout << time << endl;
  cout << output.str();
  return 0;
}