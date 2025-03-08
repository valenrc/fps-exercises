// POJ 2739 - Sum of Consecutive Primes Numbers
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

bool is_prime(int x, vector<int> primos){
  for(int i=0; i<primos.size(); i++){
    if(x%primos[i]==0) return false;
  }
  return true;
}

vector<int> generar_primos(){
  // genera todos los primos menores a 10000
  vector<int> primos;

  for(int i=2; i<10000; i++){
    if(is_prime(i, primos)){
      primos.push_back(i);
    }
  }

  return primos;
}

int main(){
	ios_base::sync_with_stdio(false);

  // generar array con los numeros primos menores a 10000
  vector<int> primos = generar_primos();
	
	int x;
	cin >> x;
	while(x){
		int res = 0;

    // sliding window ftw
    int i=0, sum=0;
      for(int j=0; j<primos.size(); j++){
      sum += primos[j];
      
      while(sum > x){
        sum -= primos[i];
        i++;
      }

      if(sum==x) res++;

      if(primos[i] > x){
        break;
      }
    }
		
		cout << res << endl;
		cin >> x;
	}
	
	return 0;
}