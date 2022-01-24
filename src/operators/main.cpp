// #define __FREAK__
#include "roman.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  RomanNumber r1("X");
  RomanNumber r2("IV");
  cout << boolalpha;
  cout << "01 | r1           = " << r1 << endl;
  cout << "02 | r2           = " << r2 << endl;
  cout << "03 | r1 == r2     = " << (r1 == r2) << endl;
  cout << "04 | r1 != r2     = " << (r1 != r2) << endl;
  cout << "05 | r1 <= r2     = " << (r1 <= r2) << endl;
  cout << "06 | r1 >= r2     = " << (r1 >= r2) << endl;

  // Jetzt sind unsere Operatoren symmetrisch!
  cout << "07 | \"XI\"s == r2  = " << ("XI"s == r2) << endl;
  cout << "08 | r2 == \"XI\"s  = " << (r2 == "XI"s) << endl;
}
