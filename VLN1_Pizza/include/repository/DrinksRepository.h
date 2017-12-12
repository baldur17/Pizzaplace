#ifndef DRINKSREPOSITORY_H
#define DRINKSREPOSITORY_H
#include "Drinks.h"
#include <fstream>
#include <vector>
#include <cstdlib>

class DrinksRepository
{
    public:
        void addDrink(const Drinks& drink);
        Drinks parse_string(string line);
        vector<Drinks> fill_locations_vector();
    private:
        vector<Drinks> vector_of_drinks;
};

#endif // DRINKSREPOSITORY_H
