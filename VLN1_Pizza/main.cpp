#include <iostream>
#include <stdlib.h>
#include <MainUI.h>
#include <Order.h>


///muna taka ut, nota til ad testa;
#include <Pizza.h>
#include <Topping.h>
#include <vector>
#include <Order.h>
#include <Order_repository.h>

using namespace std;

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
    cout << endl << endl;
    cout << "Order includes" << endl;
    cout << "Topping: " << topping << endl;
    cout << "Drinks: " << o.getDrinks().getBrand() << " " << o.getDrinks().getSize() << endl;
    cout << "Location: " << o.getLocation().getCity() << " " << o.getLocation().getStreet() << endl;
    temp = status(o.getFlag());
    cout << "Pizza Status: " << temp << endl;
    cout << "Order Total Price: " << o.getPizza().getPrice() + temp_topping[0].getPrice() + o.getDrinks().getPrice() << endl;

}
int main()
{
    Order_repository o_repo;
    vector<vector<Topping> > t;
    t = o_repo.fill_topping_order_vector();
    for (unsigned int i = 0; i < t.size(); i++)
    {
       for(unsigned int j = 0; j < t[i].size(); j++)
        cout << t[i][j];
        system("pause");
    }
    system("pause");

    MainUI mainui;
    mainui.startUI();


    return 0;
}
