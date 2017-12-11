#include "ManagementUI.h"

void ManagementUI::startUI()
{
    char input = '0';
    while(input != '5')
    {
        system("cls");
        cout << endl;
        cout << "\tMANAGEMENT MENU" << endl << endl;
        cout << "\t01. ADD TOPPING TO SYSTEM" << endl << endl;
        cout << "\t02. ADD BASE PIZZA TO SYSTEM" << endl << endl;
        cout << "\t03. PLACEHOLDER" << endl << endl;
        cout << "\t04. PLACEHOLDER" << endl << endl;
        cout << "\t05. EXIT" << endl << endl;
        cout << "\tSelect Your Option <1-5> ";
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
