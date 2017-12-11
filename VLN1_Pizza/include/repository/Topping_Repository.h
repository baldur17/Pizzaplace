#ifndef TOPPING_REPOSITORY_H
#define TOPPING_REPOSITORY_H
#include "Topping.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Topping_Repository
{
    public:
        vector<Topping> fill_topping_vector();
        void add_to_file(Topping t);
        Topping parse_string(string line);
        vector<Topping> remove_duplicate(Topping t, vector<Topping> top);

    private:
        vector<Topping> vector_of_topping;
};

#endif // TOPPING_REPOSITORY_H
