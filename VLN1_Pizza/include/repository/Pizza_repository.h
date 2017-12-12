#ifndef PIZZA_REPOSITORY_H
#define PIZZA_REPOSITORY_H

#include "Pizza.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class Pizza_repository
{
    public:
        void add_to_file(Pizza p);
        vector<Pizza> fill_basepizza_vector();
        Pizza parse_string(string line);
        vector<Pizza> remove_duplicate(Pizza p, vector<Pizza> p_vector);
    private:
        vector<Pizza> vector_of_basepizza;
};

#endif // PIZZA_REPOSITORY_H
