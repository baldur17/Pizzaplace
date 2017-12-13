#include "Topping.h"

Topping::Topping()
{
    name = "";
    price = 0;
}
Topping::Topping(string name, int price)
{
    this->name = name;
    this->price = price;
}
string Topping::getName() const
{
    return name;
}
int Topping::getPrice() const
{
    return price;
}
void Topping::setName(string name)
{
    this->name = name;
}
void Topping::setPrice(int price)
{
    this->price = price;
}
ostream& operator << (ostream& out, const Topping& t)
{
    out << t.name << "," << t.price << ",";
    return out;
}
istream& operator >> (istream& in, Topping& t)
{
    in >> t.name >> t.price;
    return in;
}
