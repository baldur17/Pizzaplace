#ifndef LOCATIONS_H
#define LOCATIONS_H
#include<string>
#include<iostream>
using namespace std;

class Locations {
    public:
        Locations();
        Locations(string city, string street);
        string getCity() const;
        string getStreet() const;
        friend ostream& operator << (ostream& out, const Locations& location);

    private:
        string city;
        string street;
};

#endif // LOCATIONS_H
