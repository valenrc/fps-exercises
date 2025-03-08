// POJ 1005 - I Think I Need a Houseboat
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;

# define PI 3.14159265358979323846

int main(){
	double x,y;
	int test_cases;
	cin >> test_cases;
	for(int i = 1; i<=test_cases; i++){
		cin >> x; cin >> y;
		
		// calcular el area del semicirculo con centro en (0,0) que pasa por el punto (x,y)
		double area = (x*x + y*y) * PI / 2;
		// redondear
		int y = ceil(area/50);

		printf("Property %d: This property will begin eroding in year %d.\n", i, y);
	}
	
	cout << "END OF OUTPUT.\n";
}