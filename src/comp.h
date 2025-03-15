#ifndef COMP_H
#define COMP_H

#include <iostream>   // cout, cin
#include <algorithm>  // sort, binary_search, lower_bound, upper_bound
#include <cmath>      // sqrt, pow, abs, ceil, floor
#include <cstdio>     // printf, scanf
#include <cstring>    // memset, strcpy, strcmp, strlen
#include <utility>    // pair, make_pair, swap, min, max
#include <sstream>    // stringstream, istringstream, ostringstream
#include <iomanip>    // setprecision, fixed, showpoint

// Data structures
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

// Data types
typedef long long ll;
typedef vector<int>    vi;
typedef vector<string> vs;
typedef vector<vi>     vvi;
typedef pair<int,int>  ii;
typedef vector<ii>     vii;
typedef pair<double, double> pdd;

// Macros
#define forn(i,n)     for(int i=0;i<n;i++)
#define fordn(i,d,n)  for(int i=d;i<n;i++)
#define forall(i, c)  for (vector<int>::iterator i = (c).begin(); i != (c).end(); ++i)
#define pb push_back

// Functions
void print_vi(vi& v){
  forall(i,v) cout << *i << " ";
  cout << endl;
}

#endif