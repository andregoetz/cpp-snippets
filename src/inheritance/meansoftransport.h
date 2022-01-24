#ifndef CPP_UEBUNGEN_MEANSOFTRANSPORT_H
#define CPP_UEBUNGEN_MEANSOFTRANSPORT_H

#include <iostream>

class MeansOfTransport {
private:
    unsigned int seats;

public:
    explicit MeansOfTransport(unsigned int _seats) : seats(_seats) {
        std::cout << "MeansOfTransport()" << std::endl;
    }

    unsigned int getSeats() const {
        return seats;
    }
};

#endif //CPP_UEBUNGEN_MEANSOFTRANSPORT_H
