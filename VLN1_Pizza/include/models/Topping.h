#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Topping
{
    public:
        Topping();
        Topping(string name, int price);
        string getName() const;
        int getPrice() const;
        void setName(string name);
        void setPrice(int price);
        friend ostream& operator << (ostream& out, const Topping& t);
        friend istream& operator >> (istream& in, Topping& t);
    private:
        string name;
        int price;
};

#endif // TOPPING_H
