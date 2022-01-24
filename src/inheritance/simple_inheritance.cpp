#include <iostream>

using namespace std;

class Base {
private:
    int mine; //not accessible in Derived

protected:
    int our; //accessible in Derived

public:
    Base(int _mine, int _our) : mine(_mine), our(_our) {}

    virtual int get_mine() const {
        cout << "Mine in Base()" << endl;
        return mine;
    }

    virtual int get_our() const = 0; //pure virtual --> Base becomes abstract
};

class Derived : public Base { //"isA" inheritance
public:
    Derived(int not_mine, int _our) : Base(not_mine, _our) {}

    int get_mine() const override {
        cout << "Mine in Derived()" << endl;
        return Base::get_mine();
    }

    int get_our() const override {
        return our;
    }
};

int main() {
    Derived d(1, 2);
    cout << d.get_mine() << endl;
    cout << d.Base::get_mine() << endl; //call to base class method
    cout << d.get_our() << endl;
    return 0;
}
