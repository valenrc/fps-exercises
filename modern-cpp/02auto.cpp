#include <print>
using namespace std;

int main(){
  auto j = 1; // j es de tipo int
  auto x{3.5}; // x es de tipo double usando uniform initialization
  // auto q;  -- error: no se puede deducir el tipo de q

  byte b{250}; // b es de tipo byte [0,255]

  println("j = {}, x = {}", j, x);
  println("b = {}", to_integer<int>(b));  // conversion de byte a int

  return 0;
}