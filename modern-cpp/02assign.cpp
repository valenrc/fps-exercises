#include <print>
using namespace std;

int main(){
  int i=1;
  double x = 3.5;

  println("(1) i = {}, x = {}", i, x);

  // implicit casts
  i = 1.14;   // narrowing cast - hay perdida de informacion, se redondea a 1
  x = 3;      // widening cast - no hay perdida de información, se convierte a 3.0
  
  println("(2) i = {}, x = {}", i, x);

  i = 1;
  x = 3.5;

  i = static_cast<int>(1.14); // explicit cast
  x = static_cast<double>(3); // explicit cast
  println("(3) i = {}, x = {}", i, x);

  int j = {static_cast<int>(3.14)};  // uniform initialization
  int k = {42};                      // equivalente a int k{42};

  println("(4) j = {}, k = {}", j, k);

  // narrowing cast attempt
  j = 3.14;
  k = 42.195;
  println("(5) j = {}, k = {}", j, k); // no permite el casteo

  return 0;
}