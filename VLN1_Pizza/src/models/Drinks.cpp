#include "Drinks.h"
Drinks::Drinks()
{
    brand = "";
    size = "";
    price = 0;
}
Drinks::Drinks(string brand, string size, int price) {
    this->brand = brand;
    this->size = size;
    this->price = price;
}

string Drinks::getBrand() const {
    return brand;
}

string Drinks::getSize() const {
    return size;
}

int Drinks::getPrice() const {
    return price;
}

ostream& operator << (ostream& out, const Drinks& drink) {
    out << drink.brand << "," << drink.size << "," << drink.price << "," << endl;
    return out;
}
