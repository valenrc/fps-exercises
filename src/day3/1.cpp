// POJ 2080 - Calendar
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

int days_by_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const string daysn[] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
const int iny = 2000;

int dias_ano(int ano){
  if(ano%100 == 0){
    return (ano%400 == 0) ? 366 : 365;
  }
  return (ano%4 == 0) ? 366 : 365;
}

int dm(int mm, int y){
  if(mm == 2){
    return (dias_ano(y) == 366) ? 29 : 28;
  }else{
    return days_by_month[(mm-1)];
  }
}

int main(){
  int n; cin >> n;
  while((n)!=-1){
    string dayn = daysn[n%7];

    //ano
    int dd = n;
    int a = 0;

    while(dd>=dias_ano(iny+a)){
      dd -= dias_ano(iny+a);
      a++;
    }

    //mes
    int mm = 1;
    while(dd >= dm(mm,iny+a)){
      //cout << dd << " " << mm << " " << endl;
      dd -= dm(mm,iny+a);
      mm++;
    }

    // tiene un error
    cout << iny+a << "-";
    if(mm<10) cout << "0";
    cout << mm << "-";
    if(dd<9) cout << "0";
    cout << dd+1 << " " << dayn << endl;
    cin >> n;
  }
}