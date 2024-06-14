#pragma once
#include "Rental.h"

enum OP_STATUS{
    OK,
    ERROR,
};

namespace rental_service {
    
    class Rental;

    class RentalService {
    public:
        RentalService();
        virtual ~RentalService();

        Rental *rental = nullptr;

        OP_STATUS add();
        OP_STATUS remove();
        OP_STATUS search();
    };
}