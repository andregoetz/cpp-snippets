#include<iostream>
#include "list.h"

using namespace std;

int main() {
    cout << "List with int:" << endl;
    {
        List<int> list;
        list.add(1);
        list.add(2);
        list.add(3);
        cout << list << endl;
        list.clear();
        cout << list << endl;
    }

    cout << endl;

    cout << "List with double:" << endl;
    {
        List<double> list;
        list.add(1.5);
        list.add(2.5);
        list.add(3.5);
        cout << list << endl;
        list.clear();
        cout << list << endl;
    }

    cout << endl;

    cout << "List with string:" << endl;
    {
        List<string> list;
        list.add("a");
        list.add("mine");
        list.add("c");
        cout << list << endl;
        list.clear();
        cout << list << endl;
    }
    return 0;
}
