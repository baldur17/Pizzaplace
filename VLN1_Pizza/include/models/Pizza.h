#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"
#include <iostream>
#include <vector>
#include <string>

#include <cstdlib>

using namespace std;

class Pizza
{
    public:
        Pizza();
        Pizza(vector<Topping> topping, char pizza_size, int price);
        Pizza(char pizza_size, int price);

        char getPizza_size();
        void setSize_price(int size_price);
        int getPrice();
        vector<Topping> getTopping();
        void setPizza_size(char pizza_size);
        void setTopping(vector<Topping> topping);
        friend ostream& operator << (ostream& out, const Pizza& p);
        friend istream& operator >> (istream& in, Pizza& p);
    private:
        vector<Topping> topping;
        ///vector af klasanum Topping;
        char pizza_size;
        int size_price;
        ///Pizza size char breyta, 's' = small, 'm' = medium, 'l' = large;
        ///b�ta vi� seinna kannski t�pu, thin crust etc byrja � �essu (einfaldara)
};

#endif // PIZZA_H
