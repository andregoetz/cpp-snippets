#include <iostream>
#include "constructors.h"

using namespace std;

int main() {
    OneAttribute o;
    OneAttribute o1{};
    OneAttribute o2 = {};
    cout << o.num << endl;

    OneAttribute oNum = OneAttribute{7};
    OneAttribute oNum1 = {7};
    OneAttribute oNum2{7};
    OneAttribute oNum3 = 7;
    cout << oNum.num << endl;

    TwoAttribute tDefault{};
    cout << tDefault.a << "," << tDefault.b << endl;
    TwoAttribute tOne{3};
    cout << tOne.a << "," << tOne.b << endl;
    TwoAttribute t{3, 4};
    cout << t.a << "," << t.b << endl;
    TwoAttribute tInitilazier = {5, 6};
    cout << tInitilazier.a << "," << tInitilazier.b << endl;

//    A a3 = 7; //not allowed beacause explicit
    A a = A(7);
    A a1 = A(a);
    A a2 = A(move(a));
    return 0;
}
