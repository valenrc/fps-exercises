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

  return 0;
}