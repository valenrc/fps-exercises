// POJ 1504 - Adding Reverssed Numbers
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

vi sumar(vi v1,vi v2){
  vi v3;

  // algoritmo para sumar - aritmetica basica
  int carry = 0;
  for(int i=v1.size()-1; i>=0; i--){
    //cout << i << endl;
    //cout << "sumando " << v1[i] << " + " << v2[i] << " + " << carry << endl;
    int sum = v1[i] + v2[i] + carry;
    if(sum >= 10){
      carry = 1;
      sum -= 10;
    }else{
      carry = 0;
    }
    //cout << "sum = " << sum << " carry = " << carry << endl;
    v3.push_back(sum);
  }

  if(carry){
    v3.push_back(carry);
  }
   
  // eliminar los ceros que queden al principio
  while(v3.size() > 1 && v3[0] == 0){
    v3.erase(v3.begin());
  }

  // devolverlo por valor
  return v3;
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
      v1[ml-1-j] = s1[j] - '0';
    }
    forn(j, n2){
      v2[ml-1-j] = s2[j] - '0';
    }

    vector<int> v3 = sumar(v1, v2);

    //print_vi(v3);

    // imprimir 
    forn(j, v3.size()){
      cout << v3[j];
    }

    cout << endl;
  }

  return 0;
}