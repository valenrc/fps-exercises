// POJ 1298 - The Hardest Problem Ever
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

// Implementaciones para grafos
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define forn(i,n)     for(int i=0;i<n;i++)
#define fordn(i,d,n)  for(int i=d;i<n;i++)
#define forall(i, c)  for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)

#define pb push_back

char decypher(char c){
  // c es un caracter cifrado
  // A = 65, B = 66, C = 67, ..., Z = 90
  if(int(c) < 65 || int(c) > 90){
    return c;
  }
  return char(65 + ((int(c) - 65 + 21) % 26));
}

int main(){
  /*
  char a = 'A';
  char z = 'Z';
  for(int i=int(a); i<=int(z); i++){
    cout << char(i) << " -> ";
    cout << decypher(char(i)) << endl;
  }
  */

  string s;
  getline(cin, s);

  while(s != "ENDOFINPUT"){
    getline(cin, s);
    //cout << s << endl;

    forn(i, s.size()){
      cout << decypher(s[i]);
    }
    cout << endl;

    getline(cin, s);
    getline(cin, s);
  }
}