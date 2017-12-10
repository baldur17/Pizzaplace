#include "ManagementUI.h"

void ManagementUI::startUI()
{
    char input = '0';
    while(input != '5')
    {
        cout << endl;
        cout << "\tMANAGEMENT MENU" << endl << endl;
        cout << "\t01. PLACEHOLDER" << endl << endl;
        cout << "\t02. PLACEHOLDER" << endl << endl;
        cout << "\t03. PLACEHOLDER" << endl << endl;
        cout << "\t04. PLACEHOLDER" << endl << endl;
        cout << "\t05. EXIT" << endl << endl;
        cout << "\tSelect Your Option <1-5> ";
        cin >> input;
        validate_user_input(input);
    }
}
char ManagementUI::validate_user_input(char input)
{
    if (input == '1'){
            Topping t;
            t = create_topping();
            t_service.write_topping(t);
        }
    if (input == '2'){

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
