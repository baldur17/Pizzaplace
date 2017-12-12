#include "Locations.h"
Locations::Locations()
{
    city = "";
    street = "";
}
Locations::Locations(string city, string street) {
    this->city = city;
    this->street = street;
}

string Locations::getCity() const {
    return city;
}

string Locations::getStreet() const {
    return street;
}

ostream& operator << (ostream& out, const Locations& location) {
    out << location.city << "," << location.street << "," << endl;
    return out;
}
