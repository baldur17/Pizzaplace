#include "ManagementUI.h"

void ManagementUI::startUI()
{
    char input = '0';
    while(input != '6')
    {
        system("cls");
        cout << endl;
        cout << "\tMANAGEMENT MENU" << endl << endl;
        cout << "\t01. ADD TOPPING TO SYSTEM" << endl << endl;
        cout << "\t02. ADD BASE PIZZA TO SYSTEM" << endl << endl;
        cout << "\t03. ADD DRINKS TO SYSTEM" << endl << endl;
        cout << "\t04. ADD FRANCHISE LOCATION TO SYSTEM" << endl << endl;
        cout << "\t05. BACK" << endl << endl;
        cout << "\t06. EXIT" << endl << endl;
        cout << "\tSelect Your Option <1-6> ";
        cin >> input;
        system("cls");
        validate_user_input(input);
    }
}
char ManagementUI::validate_user_input(char input)
{
    if (input == '1'){
            Topping t;
            try{
            t = create_topping();
            t_service.write_topping(t);
            }
            catch(Invalid_price_exception){
                cout << endl;
                cout << "\tInvalid Price!" << endl << endl;
                system("pause");
            }
            catch(Invalid_name_exception){
                cout << endl;
                cout << "\tInvalid Name!" << endl << endl;
            }
        }
    if (input == '2'){
            Pizza p;
            try{
            p = create_pizza();
            p_service.write_pizza(p);
            }
            catch(Invalid_pizza_size_exception){
                cout << endl;
                cout << "\tInvalid Size!" << endl << endl;
                system("pause");
            }
        }
    if (input == '3'){
            Drinks d;
            try{
            d = create_drinks();
            d_service.addDrink(d);
            }
            catch(Invalid_price_exception){
                cout << endl;
                cout << "\tInvalid Price!" << endl << endl;
                system("pause");
            }
        }
    if (input == '4'){
            Locations l;
            l = create_location();
            l_service.addLocation(l);
        }
    if (input == '5'){
            MainUI mainui;
            mainui.startUI();
        }
    if (input == '6'){
            exit(0);
        }
    else{
            ///throw exception, invalid input;
            return '0';
    }
}
Topping ManagementUI::create_topping()
{
    string name;
    int price;
    cout << "\tEnter Topping Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "\tEnter Topping Price ";
    cin >> price;
    Topping t(name, price);
    return t;
}
Pizza ManagementUI::create_pizza()
{
    char size;
    int size_price;
    cout << "\tEnter Pizza Size: ";
    cin >> size;
    cout << "\tEnter Size Price: ";
    cin >> size_price;
    Pizza p(size, size_price);
    return p;
}
Drinks ManagementUI::create_drinks()
{
    string brand;
    string size;
    int price;
    cout << "\tEnter Brand Name: ";
    cin.ignore();
    getline(cin, brand);
    cout << "\tEnter Size: ";
    getline(cin, size);
    cout << "\tEnter Price: ";
    cin >> price;

    Drinks drink(brand, size, price);
    return drink;
}
Locations ManagementUI::create_location()
{
    string city;
    string street;

    cout << "\tEnter City Name: ";
    cin.ignore();
    getline(cin, city);
    cout << "\tEnter Street Name: ";
    getline(cin, street);
    Locations location(city, street);
    return location;


}
