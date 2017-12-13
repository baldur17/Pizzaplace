#ifndef ORDER_REPOSITORY_H
#define ORDER_REPOSITORY_H
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Order.h"

class Order_repository
{
    public:
        void order_to_file(Order o);
        vector<Order> fill_order_vector();
        Order parse_string(string line);
        void topping_to_file(vector<Topping> t);
        vector<vector<Topping> > fill_topping_order_vector();
        vector<Topping> parse_topping_string(string line);
        vector<Topping> getVector_of_topping_order();
    private:
        vector<Order> vector_of_order;
        vector<Topping> vector_of_topping_order;
};

#endif // ORDER_REPOSITORY_H
