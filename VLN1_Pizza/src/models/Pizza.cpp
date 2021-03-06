#include "Pizza.h"

Pizza::Pizza()
{
    pizza_size = '\0';
}
Pizza::Pizza(vector<Topping> topping, char pizza_size,int price)
{
    this->topping = topping;
    this->pizza_size = pizza_size;
    this->size_price = price;
}
Pizza::Pizza(char pizza_size,int price)
{
    this->pizza_size = pizza_size;
    this->size_price = price;
}
char Pizza::getPizza_size()
{
    return pizza_size;
}
vector<Topping> Pizza::getTopping()
{
    return topping;
}
int Pizza::getPrice()
{
    return size_price;
}
void Pizza::setPizza_size(char pizza_size)
{
    this->pizza_size = pizza_size;
}
void Pizza::setTopping(vector<Topping> topping)
{
    this->topping = topping;
}
void Pizza::setSize_price(int size_price)
{
    this->size_price = size_price;
}
ostream& operator << (ostream& out, const Pizza& p)
{
    out << p.pizza_size << "," << p.size_price << ",";
    /*for (unsigned int i = 0; i < p.topping.size(); i++)
    {
        cout << p.topping[i].getName() << "," << p.topping[i].getPrice() << "," << endl;
    }*/
    return out;
}
istream& operator >> (istream& in, Pizza& p)
{
    int topcnt = 0;
    cin >> topcnt;
    in >> p.pizza_size;
    for (int i = 0; i < topcnt; i++)
    {
        Topping t;
        cin >> t;
        p.topping.push_back(t);
    }
    return in;
}
