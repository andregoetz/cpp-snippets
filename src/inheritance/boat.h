#ifndef CPP_UEBUNGEN_BOAT_H
#define CPP_UEBUNGEN_BOAT_H

#include "vehicle.h"
#include "meansoftransport.h"

class Boat : public virtual MeansOfTransport, public Vehicle {
public:
    explicit Boat(unsigned int _max_v, unsigned int _seats = 1) : MeansOfTransport(_seats), Vehicle(_max_v) {
        std::cout << "Boat()" << std::endl;
    }
};

#endif //CPP_UEBUNGEN_BOAT_H
