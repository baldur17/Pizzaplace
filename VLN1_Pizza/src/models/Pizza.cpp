#include "Pizza.h"

Pizza::Pizza()
{
    pizza_size = '\0';
}
Pizza::Pizza(vector<Topping> topping, char pizza_size)
{
    this->topping = topping;
    this->pizza_size = pizza_size;
}
char Pizza::getPizza_size()
{
    return pizza_size;
}
vector<Topping> Pizza::getTopping()
{
    return topping;
}
void Pizza::setPizza_size(char pizza_size)
{
    this->pizza_size = pizza_size;
}
void Pizza::setTopping(vector<Topping> topping)
{
    this->topping = topping;
}
ostream& operator << (ostream& out, const Pizza& p)
{
    out << p.pizza_size << ",";
    for (unsigned int i = 0; i < p.topping.size(); i++)
    {
        cout << p.topping[i].getName() << "," << p.topping[i].getPrice() << "," << endl;
    }
    return out;
}
istream& operator >> (istream& in, Pizza& p)
{
    ///overload fyrir istream pizza, hugsanlega breyta þessu yfir í sér fall
    ///í eitthverjum ui klasa svo það sé auðveldara að skrifa í skrá;
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
