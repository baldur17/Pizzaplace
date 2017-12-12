#include <iostream>
#include <stdlib.h>
#include <MainUI.h>
#include <Order.h>


///muna taka ut, nota til ad testa;
#include <Pizza.h>
#include <Topping.h>
#include <vector>
#include <Order.h>

using namespace std;
/*
string status(char flag)
{
    string flag_status;
    if(flag == 'n')
    {
        flag_status = "Not Ready";
    }
    else if(flag == 'p')
    {
        flag_status = "Processing";
    }
    else if(flag == 'r')
    {
        flag_status = "Ready";
    }
    return flag_status;

}
void write_order_to_screen(Order o)
{
    string temp;
    vector<Topping> temp_topping;
    temp_topping = o.getPizza().getTopping();
    string topping = temp_topping[0].getName();
    cout << "Order include:" << endl;
    cout << "Topping: " << topping << endl;
    cout << "Drinks: " << o.getDrinks().getBrand() << " " << o.getDrinks().getSize() << endl;
    cout << "Location: " << o.getLocation().getCity() << " " << o.getLocation().getStreet() << endl;
    temp = status(o.getFlag());
    cout << "Pizza Status: " << temp << endl;

}*/
int main()
{
    /*Topping t("pepperoni", 200);
    vector<Topping> temp;
    temp.push_back(t);
    Pizza p(temp, 's', 1200);
    Drinks d("coke", "2L", 200);
    Locations l("Akureyri", "undirhlid");
    Order o(p, d, l, 'r');
    cout << o << endl;
    vector<Topping> temp_topping;
    temp_topping = o.getPizza().getTopping();
    cout << o.getPizza().getPrice() + temp_topping[0].getPrice() + o.getDrinks().getPrice() << endl;
    write_order_to_screen(o);
    system("pause");*/
    MainUI mainui;
    mainui.startUI();


    return 0;
}
