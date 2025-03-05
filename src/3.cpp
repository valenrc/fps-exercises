#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

bool is_prime(int x){
	int div = 0;
	for(int i=1; i<=x; i++){
		if(x % i == 0){
			div++;
		}
	}
	return div == 2;
}

int main(){
	// generar array con los numeros primos menores a 10000
	vector<int> primos;
	for(int i=1; i<10000; i++){
		if(is_prime(i)){
			primos.push_back(i);
		}
	}
	
	int size = primos.size();
	
	int x;
	cin >> x;
	while(x){
		int res = 0;
		
		if(is_prime(x)){
			res++;
		}
		// primo inicial	
		for(int i=0;  primos[i]<x; i++){
			// sumar los consecutivos
			int sum = 0;
			for(int j=i; j < size && sum < x; j++){
				sum += primos[j];
			}
			
			if(sum==x){
				++res;
			}
		}
		
		cout << res << endl;
		cin >> x;
	}
	
	return 0;
}