// POJ 2234 - Matches Game
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

int main(){
    int n;

    while(cin >> n){
      int res = 0;
      forn(i,n){
        int x;
        cin >> x;
        res ^= x;
      }
      if(res == 0){
        cout << "No" << endl;
      }else{
        cout << "Yes" << endl;
      }

    }
    return 0;
}
