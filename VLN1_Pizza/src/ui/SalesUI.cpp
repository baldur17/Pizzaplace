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
            Order o;
            ///o = create_order();
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
    string phone_number;
    Pizza p;
    Drinks d;
    Locations l;
    p = add_base_pizza();
    d = add_drinks();
    l = add_location();
    cout << endl;
    cout << "\tEnter Customers Phone Number : ";
    cin >> phone_number;
    Order o(p, d, l, flag, phone_number);
    order_service.add_order_to_file(o);
}
Pizza SalesUI::add_base_pizza()
{
    vector<Pizza> pizza_vector;
    Pizza_service p_service;
    char size;
    int price;
    cout << "\tBase Pizza Options" << endl;
    pizza_vector = p_service.fetch_base_pizza();
    for (unsigned int i = 0; i < pizza_vector.size(); i++)
    {
        cout << "\tPizza Size: " << pizza_vector[i].getPizza_size() << endl;
        cout << "\tPizza Price: " << pizza_vector[i].getPrice() << endl << endl;
    }
    cout << "\tEnter Pizza Size: ";
    cin >> size;
    cout << "\tEnter Size Price: ";
    cin >> price;
    Pizza p(size, price);
    return p;
}
Drinks SalesUI::add_drinks()
{
    DrinksService d_service;
    string brand;
    string size;
    int price;
    vector<Drinks> d_vector;
    cout << endl;
    cout << "\tDrink Options" << endl << endl;
    d_vector = d_service.fetch_drinks();
    for (unsigned int i = 0; i < d_vector.size(); i++)
    {
        cout << "\tDrink Brand : " << d_vector[i].getBrand() << endl;
        cout << "\tDrink Size  : " << d_vector[i].getSize() << endl;
        cout << "\tDrink Price : " << d_vector[i].getPrice() << endl << endl;
    }
    cout << "\tEnter Drink Brand : ";
    cin.ignore();
    getline(cin, brand);
    cout << "\tEnter Drink Size  : ";
    cin.ignore();
    getline(cin, size);
    cout << "\tEnter Drink Price : ";
    cin >> price;

    Drinks d(brand, size, price);
    return d;

}
Locations SalesUI::add_location()
{
    LocationsService l_service;
    string city;
    string street;
    vector<Locations> l_vector;
    l_vector = l_service.fetch_location();
    cout << endl;
    cout << "\tFranchise Locations" << endl << endl;
    for (unsigned int i = 0; i < l_vector.size(); i++)
    {
        cout << "\tFranchise City        : " << l_vector[i].getCity() << endl;
        cout << "\tFranchise Street Name : " << l_vector[i].getStreet() << endl << endl;
    }
    cout << "\tEnter City Name   : ";
    cin.ignore();
    getline(cin, city);
    cout << "\tEnter Street Name : ";
    cin.ignore();
    getline(cin, street);

    Locations l(city, street);
    return l;
}


/*string SalesUI::pizza_size_string(char size)
{

}*/
