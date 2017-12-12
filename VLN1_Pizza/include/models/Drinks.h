#ifndef DRINKS_H
#define DRINKS_H
#include<string>
#include<iostream>
using namespace std;

class Drinks {
    public:
        Drinks();
        Drinks(string brand, string size, int price);
        string getBrand() const;
        string getSize() const;
        int getPrice() const;
        friend ostream& operator << (ostream& out, const Drinks& drink);

    private:
        string brand;
        string size;
        int price;
};

#endif // DRINKS_H
