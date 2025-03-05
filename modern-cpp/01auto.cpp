/*
auto permite que el compilador deduzca el tipo de una variable en tiempo de compilación
se usa especialmente con iteradores
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
  auto x = 2;
  auto y = 3.14;
  auto z = "Hello, World!";
  cout << x << " " << y << " " << z << endl;

  //--

  vector<int> v = {1, 2, 3, 4, 5};

  // deduce que x es de tipo int
  for(auto x:v){
    cout << x << " ";
  }


  return 0;
}