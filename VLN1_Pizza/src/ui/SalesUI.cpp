#include "SalesUI.h"

void SalesUI::startUI()
{
    char input = '0';
    while(input != '5')
    {
        cout << endl;
        cout << "\tSALES MENU" << endl << endl;
        cout << "\t01. PLACE ORDER" << endl << endl;
        cout << "\t02. PLACEHOLDER" << endl << endl;
        cout << "\t03. PLACEHOLDER" << endl << endl;
        cout << "\t04. PLACEHOLDER" << endl << endl;
        cout << "\t05. EXIT" << endl << endl;
        cout << "\tSelect Your Option <1-5> ";
        cin >> input;
        system("cls");
        validate_user_input(input);
    }
}
char SalesUI::validate_user_input(char input)
{
    if (input == '1'){
            create_order();
        }
    if (input == '2'){
            order_service.retrieve_order_with_topping();
        }
    if (input == '3'){

        }
    if (input == '4'){

        }
    if (input == '5'){
            exit(0);
        }
    else{
            ///throw exception, invalid input;
            return '0';
    }
}
void SalesUI::create_order()
{
    char flag = 'n';
    int total_price;
    string phone_number;
    Pizza p;
    Drinks d;
    Locations l;
    p = add_base_pizza();
    total_price = add_topping();
    d = add_drinks();
    l = add_location();
    cout << endl;
    cout << "\tEnter Customers Phone Number : ";
    cin >> phone_number;
    cout << endl;
    Order o(p, d, l, flag, phone_number);
    total_price = total_price + p.getPrice() + d.getPrice();
    cout << "\tOrder Total Price: " << total_price;
    order_service.add_order_to_file(o);
}
int SalesUI::add_topping()
{
    int input;
    char loop;
    int topping_total_price = 0;
    vector<Topping> t_vector;
    vector<Topping> to_file;
    Topping_service t_service;
    t_vector = t_service.fetch_toppings();
    system("cls");
    cout << "\tTopping Options" << endl;
    do{
        for (unsigned int i = 0; i < t_vector.size(); i++)
        {
            cout << "\tNr." << (i + 1) << endl;
            cout << "\tTopping Name  : " << t_vector[i].getName() << endl;
            cout << "\tTopping Price : " << t_vector[i].getPrice() << endl << endl;
        }
        cout << "\tAdd Topping Nr.";
        cin >> input;
        to_file.push_back(t_vector[input - 1]);
        cout << "\tAdd Another Topping(y/n)? ";
        cin >> loop;
    }while(loop == 'y');
    for(unsigned int j = 0; j < to_file.size(); j++)
    {
        topping_total_price = topping_total_price + to_file[j].getPrice();
    }
    order_service.add_topping_to_file(to_file);
    return topping_total_price;
}
Pizza SalesUI::add_base_pizza()
{
    vector<Pizza> pizza_vector;
    Pizza_service p_service;
    int input;
    system("cls");
    cout << "\tPizza Size Options" << endl;
    pizza_vector = p_service.fetch_base_pizza();
    for (unsigned int i = 0; i < pizza_vector.size(); i++)
    {
        cout << "\tNr." << (i + 1) << endl;
        cout << "\tPizza Size: " << pizza_vector[i].getPizza_size() << endl;
        cout << "\tPizza Price: " << pizza_vector[i].getPrice() << endl << endl;
    }
    cout << "\tChoose Pizza Size Option: ";
    cin >> input;

    Pizza p(pizza_vector[input - 1]);
    return p;
}
Drinks SalesUI::add_drinks()
{
    DrinksService d_service;
    int input;
    vector<Drinks> d_vector;
    cout << endl;
    system("cls");
    cout << "\tDrink Options" << endl << endl;
    d_vector = d_service.fetch_drinks();
    for (unsigned int i = 0; i < d_vector.size(); i++)
    {
        cout << "\tNr." << (i + 1) << endl;
        cout << "\tDrink Brand : " << d_vector[i].getBrand() << endl;
        cout << "\tDrink Size  : " << d_vector[i].getSize() << endl;
        cout << "\tDrink Price : " << d_vector[i].getPrice() << endl << endl;
    }
    cout << "\tChoose Drink Option: ";
    cin >> input;

    Drinks d(d_vector[input - 1]);
    return d;

}
Locations SalesUI::add_location()
{
    LocationsService l_service;
    int input;
    string city;
    string street;
    vector<Locations> l_vector;
    l_vector = l_service.fetch_location();
    system("cls");
    cout << endl;
    cout << "\tFranchise Locations" << endl << endl;
    for (unsigned int i = 0; i < l_vector.size(); i++)
    {
        cout << "\tOption " << (i + 1) << endl;
        cout << "\tFranchise City        : " << l_vector[i].getCity() << endl;
        cout << "\tFranchise Street Name : " << l_vector[i].getStreet() << endl << endl;
    }

    cout << "\tChoose Franchise Location: ";
    cin >> input;


    Locations l = l_vector[input - 1];
    return l;
}


/*string SalesUI::pizza_size_string(char size)
{

}*/
