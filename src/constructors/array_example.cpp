#include <iostream>
#include <string>

#include "array.h"

using namespace std;

void mkSequence(Array &a) {
    for (Array::index_t i = 0; i < a.getSize(); ++i) {
        a[i] = static_cast<Array::element_t>(i);
    }
}

int main() {
    Array a(3);
    Array b({1, 2, 3});

    cout << "01 | sizeof(Array)     = " << sizeof(Array) << endl;
    cout << "02 | &Array.classname  = " << &Array::classname << endl;
    cout << "03 | Array::nameOfType = " << Array::nameOfType() << endl;

    mkSequence(a);

    cout << "04 | a = " << a << endl;
    cout << "05 | b = " << b << endl;

    a.resize(8);

    cout << "05 | a nach resize(8) = " << a << endl;

    cout << "Unsere Klasse trägt den Namen '" << Array::nameOfType() << "'" << endl;

}
