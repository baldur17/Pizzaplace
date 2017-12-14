#ifndef ORDER_H
#define ORDER_H
#include "Pizza.h"
#include "Drinks.h"
#include "Locations.h"
class Order
{
    public:
        Order();
        Order(Pizza pizza, Drinks drink, Locations location, char flag, string phone_number);
        char getFlag();
        Locations getLocation();
        Drinks getDrinks();
        Pizza getPizza();
        string getPhone_number();
        void setPizza(Pizza pizza);
        void setPhone_number(string phone_number);
        void setDrink(Drinks drink);
        void setLocation(Locations location);
        void setFlag(char flag);
        friend ostream& operator << (ostream& out, const Order& o);
    private:
        Pizza pizza;
        char flag;
        Drinks drink;
        Locations location;
        string phone_number;
};

#endif // ORDER_H
