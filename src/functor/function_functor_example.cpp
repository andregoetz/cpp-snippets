#include <iostream>
#include <functional>

using namespace std;

//std::function as parameter
double eval_std_fun(const function<double(double)> &f, double x) {
    return f(x);
}

//functor as parameter
double eval_fun_ptr(double (*f)(double), double x) {
    return f(x);
}

int main() {
    auto xPow2 = [](double x) -> auto { return x * x; };
    cout << eval_std_fun(xPow2, 1) << endl;
    cout << eval_fun_ptr(xPow2, 1) << endl;
    cout << eval_std_fun(xPow2, 2) << endl;
    cout << eval_fun_ptr(xPow2, 2) << endl;
    cout << eval_std_fun(xPow2, 3) << endl;
    cout << eval_fun_ptr(xPow2, 3) << endl;
    return 0;
}
