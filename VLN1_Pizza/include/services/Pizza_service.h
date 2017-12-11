#ifndef PIZZA_SERVICE_H
#define PIZZA_SERVICE_H
#include "Pizza.h"
#include "Pizza_repository.h"
#include "Invalid_pizza_size_exception.h"
#include <cstdlib>

using namespace std;

class Pizza_service
{
    public:
        void write_pizza(Pizza p);
        void validate_size(char size);
    private:
        Pizza_repository p_repo;
};

#endif // PIZZA_SERVICE_H
