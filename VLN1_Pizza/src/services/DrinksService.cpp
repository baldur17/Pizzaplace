#include "DrinksService.h"
#include <ctype.h>

void DrinksService::addDrink(const Drinks& drink) {
    if(isValidPrice(drink)) {
        drinksRepo.addDrink(drink);
    }
}
///muna checka hvort invalid_price virkar
bool DrinksService::isValidPrice(const Drinks& drink) {
    int price = drink.getPrice();
    if (price <= 0) {
        throw Invalid_price_exception();
    }
    return true;
}
