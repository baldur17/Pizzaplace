#ifndef TOPPING_SERVICE_H
#define TOPPING_SERVICE_H

#include "Invalid_price_exception.h"
#include "Invalid_name_exception.h"

#include <cstdlib>
#include "Topping.h"
#include "Topping_Repository.h"

using namespace std;

class Topping_service
{
    public:
        void write_topping(Topping t);
        void validate_name(string name);
        void validate_price(int price);
    private:
        Topping_Repository t_repository;
};

#endif // TOPPING_SERVICE_H
