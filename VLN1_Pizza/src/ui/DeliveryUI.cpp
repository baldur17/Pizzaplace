#include "DeliveryUI.h"
#include "MainUI.h"

using namespace std;



void DeliveryUI::select_location()
{
    int input;
    LocationsService l_service;
    vector<Locations> l;
    l = l_service.fetch_location();

    cout << "\tChoose Your Location" << endl;
    for (unsigned int i = 0; i < l.size(); i++)
    {
        cout << "\tLocation (" << (i + 1) << ")" << endl;
        cout << "\tLocation City   : " << l[i].getCity() << endl;
        cout << "\tLocation Street : " << l[i].getStreet() << endl << endl;
    }

    cout << "\tEnter Your Location : ";
    cin >> input;
    startUI(l[input - 1]);


}

void DeliveryUI::startUI(Locations l)
{
    char input = '0';
    while(input != '3')
    {
        system("cls");
        cout << endl;
        cout << "\tDELIVERY MENU" << endl << endl;
        cout << "\t01. VIEW ORDERS" << endl << endl;
        cout << "\t02. CHANGE ORDER STATUS" << endl << endl;
        cout << "\t03. BACK" << endl << endl;
        cout << "\t04. EXIT" << endl << endl;
        cout << "\tSelect Your Option <1-4> ";
        cin >> input;
        system("cls");
        validate_user_input(input, l);
    }
}

char DeliveryUI::validate_user_input(char input, Locations l)
{
    if (input == '1'){
            view_order(l);
            return '1';
        }
    else if (input == '2'){
            change_flag(l);
            return '2';
        }
    else if (input == '3'){
            MainUI mainui;
            mainui.startUI();
            return '3';
        }
    else if (input == '4'){
            exit(0);
        }
    else{
            ///throw exception, invalid input;
            return '0';
    }
return '0';
}
void DeliveryUI::change_flag(Locations l)
{
    vector<Order> o, order_location;
    vector<Topping> temp;
    vector<int> counter;
    string city = l.getCity();
    string street = l.getStreet();

    Order_service order;
    o = order.retrieve_order_with_topping();

    for (unsigned int i = 0; i < o.size(); i++)
    {
        if (o[i].getLocation().getCity() == city && o[i].getLocation().getStreet() == street)
            counter.push_back(i);
            order_location.push_back(o[i]);
    }
    for (unsigned int j = 0; j < order_location.size(); j++)
    {
        int total_price = 0;
        if(order_location[j].getFlag() == 'r')
        {
            char input;
            vector<Topping> t_vector = order_location[j].getPizza().getTopping();
            for(unsigned int k = 0; k < t_vector.size(); k++)
            {
                total_price += t_vector[k].getPrice();
            }
            total_price = total_price + order_location[j].getPizza().getPrice();
            cout << "\tPizza Size   : " << pizza_size(order_location[j].getPizza().getPizza_size()) << endl;
            cout << "\tDrink        : " << order_location[j].getDrinks().getBrand() << endl;
            cout << "\tDrink Size   : " << order_location[j].getDrinks().getSize() << endl;
            cout << "\tPhone Number : " << order_location[j].getPhone_number() << endl;
            cout << "\tTotal Price  : " << total_price << endl << endl;
            cout << "\tCHANGE FLAG(y/n)? ";
            cin >> input;
            if(input == 'y')
            {
                o[counter[j]].setFlag('d');
                order.overwrite_order_file(o);
            }
        }
    }

}
void DeliveryUI::view_order(Locations l)
{
    string input;
    vector<Order> order_vector;
    Order_service o_service;
    order_vector = o_service.retrieve_order_with_topping();

    cout << "\tEnter Phone Number To Receive Order: ";
    cin >> input;
    string city = l.getCity();
    string street = l.getStreet();
    for(unsigned int i = 0; i < order_vector.size(); i++)
    {
        if (order_vector[i].getPhone_number() == input && order_vector[i].getLocation().getCity() == city && order_vector[i].getLocation().getStreet() == street)
        {
            cout << endl;
            cout << "\tPizza Size   : " << pizza_size(order_vector[i].getPizza().getPizza_size()) << endl;
            cout << "\tToppings     : ";
            vector<Topping> t_vector;
            t_vector = order_vector[i].getPizza().getTopping();
            for (unsigned int j = 0; j < t_vector.size(); j++)
            {
                cout << t_vector[j].getName() << " ";
            }
            cout << endl;
            cout << "\tDrinks       : " << order_vector[i].getDrinks().getBrand() << " " << order_vector[i].getDrinks().getSize() << endl;
            cout << "\tOrder Status : " << order_status(order_vector[i].getFlag()) << endl;
            system("pause");
        }
    }


}
string DeliveryUI::order_status(char flag)
{
    if(flag == 'n')
    {
        return "Not Ready";
    }
    else if(flag == 'r')
    {
        return "Ready";
    }
    else if(flag == 'p')
    {
        return "Processing";
    }
    else if(flag == 'd')
    {
        return "Delivered";
    }
    else
    {
        ///throw invalid flag
    }
}
string DeliveryUI::pizza_size(char size)
{
    if(size == 's')
    {
        return "Small";
    }
    else if(size == 'm')
    {
        return "Medium";
    }
    else if(size == 'l')
    {
        return "Large";
    }
    else
    {
        ///throw invalid flag
    }
}
