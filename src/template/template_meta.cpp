#include<iostream>

using namespace std;

template<int b, int n>
struct BpowN;

template<int n>
struct BpowN<1, n> {
    static constexpr const int value = 1;
};

template<int b>
struct BpowN<b, 0> {
    static constexpr const int value = 1;
};

template<int b>
struct BpowN<b, 1> {
    static constexpr const int value = b;
};

template<int b, int n>
struct BpowN {
    static constexpr const int value = BpowN<b, n - 1>::value * b;
};

int main() {
    {
        cout << "1 hoch etwas ist immer 1:" << endl;
        const int b = 1, n = 2;
        const auto res = BpowN<b, n>::value;
        cout << b << "^" << n << " = " << res << endl;
    }

    cout << endl;

    {
        cout << "Etwas hoch 0 ist immer 1:" << endl;
        const int b = 2, n = 0;
        const auto res = BpowN<b, n>::value;
        cout << b << "^" << n << " = " << res << endl;
    }

    cout << endl;

    {
        cout << "Etwas hoch 1 ist immer es selbst:" << endl;
        const int b = 2, n = 1;
        const auto res = BpowN<b, n>::value;
        cout << b << "^" << n << " = " << res << endl;
    }

    cout << endl;

    {
        cout << "Beispiel mit bekannten Werten:" << endl;
        const int b = 2, n = 2;
        const auto res = BpowN<b, n>::value;
        cout << b << "^" << n << " = " << res << endl;
    }
    return 0;
}
