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

bool k = true;
int main(){
  string s;
  while(getline(cin,s)){
    forn(i,s.size()){
      if(s[i] == '"'){
        if(k) cout << "``";
        else cout << "''";
        k = !k;
      }else{
        cout << s[i];
      }

    }
    cout << endl;
  }
}