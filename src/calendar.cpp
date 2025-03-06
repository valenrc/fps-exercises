#include "comp.h"

const int days_by_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string daysn[] = {"Sat", "Sun","Mon", "Tue", "Wed", "Thu", "Fri"};
const int iny = 2000;

int dias_año(int año){
  if(año%4 == 0 && año%100 != 0){
    if(año%400 == 0){
      return 364;
    }else{
      return 365;
    }
  }else return 366;
}

int main(){
  int n; cin >> n;

  while((n--)!=-1){
    string dayn = daysn[n%7];

    //año
    int dd = n;
    int a = 0;
    while(dd>364){
      dd -= dias_año(iny+a);
      a++;
    }

    //mes
    int mm = 1;
    while(dd > days_by_month[mm]){
      dd -= days_by_month[mm];
      mm++;
    }

    // tiene un error
    cout << iny+a << " "<< mm << " " << dd << endl;
    cin >> n;
  }
}