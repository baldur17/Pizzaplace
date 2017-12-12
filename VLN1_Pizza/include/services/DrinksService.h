#ifndef DRINKSSERVICE_H
#define DRINKSSERVICE_H

#include "Drinks.h"
#include "DrinksRepository.h"
//#include "InvalidPriceException.h"
#include "Invalid_price_exception.h"
class DrinksService
{
    public:
        void addDrink(const Drinks& drinks);

    private:
        DrinksRepository drinksRepo;
        bool isValidPrice(const Drinks& drink);
};

#endif // DRINKSSERVICE_H
