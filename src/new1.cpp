#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	
	double x;				// input
	double sum = 0;	// result
	double avg;
	
	for(int i=0; i<12; i++){
		cin >> x;
		sum += x;
	}
	
	avg = sum/12;
	
	printf("$%.2f", avg);
	return 0;
}