// POJ 1552 - Doubles
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main(){
	int x;
	
	cin >> x;
	while(x!= -1){
		int res = 0;
		vector<int> list;
		
		while(x!=0){
			list.push_back(x);
			cin >> x;
		}
		
		for(int i=0; i<list.size(); i++){
			for(int j=i+1; j<list.size(); j++){
				if(list[i]*2 == list[j] || list[j]*2 == list[i]){
					res++;
				}
			}
		}
		cout << res << "\n";
		cin >> x;		
	}
	return 0;
}