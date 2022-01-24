#include<iostream>
#include<string>

using namespace std;

template<typename T>
string getType(T t) {
    return "unbekannter Typ: "s + typeid(t).name();
}

template<>
string getType<int>(int i) {
    return "int";
}

template<>
string getType<unsigned int>(unsigned int ui) {
    return "unsigned int";
}

template<>
string getType<char>(char c) {
    return "char";
}

template<>
string getType<bool>(bool b) {
    return "bool";
}

int main() {
    // Ausgabe
    int i;
    cout << getType(i) << endl; // int
    unsigned int ui;
    cout << getType(ui) << endl; // unsigned int
    char c;
    cout << getType(c) << endl; // char
    bool b;
    cout << getType(b) << endl; // bool
    // Annahme: float ist nicht in getType() berücksichtigt:
    float f;
    cout << getType(f) << endl; // unbekannter Typ!
}
