#include <iostream>
#include <sstream>
#include <functional>

using namespace std;

//std::function_ptr as parameter
string double_to_string_with_std_fun(const function<string(double)> &f, double x) {
    return f(x);
}

//function pointer as parameter
string double_to_string_with_fun_ptr(string (*f)(double), double x) {
    return f(x);
}

int main() {
    auto xPow2 = [](double x) -> auto {
        std::stringstream sstr;
        sstr << x << " als string";
        return sstr.str();
    };
    cout << double_to_string_with_std_fun(xPow2, 1) << endl;
    cout << double_to_string_with_fun_ptr(xPow2, 1) << endl;
    cout << double_to_string_with_std_fun(xPow2, 2) << endl;
    cout << double_to_string_with_fun_ptr(xPow2, 2) << endl;
    cout << double_to_string_with_std_fun(xPow2, 3) << endl;
    cout << double_to_string_with_fun_ptr(xPow2, 3) << endl;
    return 0;
}
