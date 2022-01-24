#ifndef CPP_UEBUNGEN_VEHICLE_H
#define CPP_UEBUNGEN_VEHICLE_H

#include <iostream>

class Vehicle {
private:
    unsigned int max_v;

public:
    Vehicle(unsigned int _max_v) : max_v(_max_v) {
        std::cout << "Vehicle()" << std::endl;
    }

    unsigned int getMaxV() const {
        return max_v;
    }
};

#endif //CPP_UEBUNGEN_VEHICLE_H
