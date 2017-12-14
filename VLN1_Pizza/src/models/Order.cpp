#include "Order.h"

Order::Order()
{
    flag = 'n';
}
Order::Order(Pizza pizza, Drinks drink, Locations location, char flag, string phone_number)
{
    this->pizza = pizza;
    this->drink = drink;
    this->location = location;
    this->flag = flag;
    this->phone_number = phone_number;
}
string Order::getPhone_number()
{
    return phone_number;
}
Pizza Order::getPizza()
{
    return pizza;
}
Drinks Order::getDrinks()
{
    return drink;
}
Locations Order::getLocation()
{
    return location;
}
char Order::getFlag()
{
    return flag;
}
void Order::setPizza(Pizza pizza)
{
    this->pizza = pizza;
}
void Order::setPhone_number(string phone_number)
{
    this->phone_number = phone_number;
}
void Order::setDrink(Drinks drink)
{
    this->drink = drink;
}
void Order::setLocation(Locations location)
{
    this->location = location;
}
void Order::setFlag(char flag)
{
    this->flag = flag;
}
ostream& operator << (ostream& out, const Order& o)
{
    out << o.pizza << o.drink << o.location << o.flag << "," << o.phone_number << "," << endl;
    return out;
}
