#ifndef CPP_UEBUNGEN_AUTOMOBILE_H
#define CPP_UEBUNGEN_AUTOMOBILE_H

#include "vehicle.h"
#include "meansoftransport.h"

class Automobile : public virtual MeansOfTransport, public Vehicle {
public:
    explicit Automobile(unsigned int _max_v, unsigned int _seats = 1) : MeansOfTransport(_seats), Vehicle(_max_v) {
        std::cout << "Automobile()" << std::endl;
    }
};

#endif //CPP_UEBUNGEN_AUTOMOBILE_H
