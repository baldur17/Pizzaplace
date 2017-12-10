#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pizza
{
    public:
        Pizza();
        Pizza(vector<Topping> topping, char pizza_size);
        char getPizza_size();
        vector<Topping> getTopping();
        void setPizza_size(char pizza_size);
        void setTopping(vector<Topping> topping);
        friend ostream& operator << (ostream& out, const Pizza& p);
        friend istream& operator >> (istream& in, Pizza& p);
    private:
        vector<Topping> topping;
        ///vector af klasanum Topping;
        char pizza_size;
        ///Pizza size char breyta, 's' = small, 'm' = medium, 'l' = large;
        ///bæta við seinna kannski týpu, thin crust etc byrja á þessu (einfaldara)
};

#endif // PIZZA_H
