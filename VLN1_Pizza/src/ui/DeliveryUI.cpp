#include "DeliveryUI.h"
#include "MainUI.h"

using namespace std;

DeliveryUI::DeliveryUI()
{

}

void DeliveryUI::startUI()
{
    char input = '0';
    while(input != '6')
    {
        system("cls");
        cout << endl;
        cout << "\tMANAGEMENT MENU" << endl << endl;
        cout << "\t01. VIEW ORDERS" << endl << endl;
        cout << "\t02. PLACEHOLDER" << endl << endl;
        cout << "\t03. PLACEHOLDER" << endl << endl;
        cout << "\t04. PLACEHOLDER" << endl << endl;
        cout << "\t05. BACK" << endl << endl;
        cout << "\t06. EXIT" << endl << endl;
        cout << "\tSelect Your Option <1-6> ";
        cin >> input;
        system("cls");
        validate_user_input(input);
    }
}

char DeliveryUI::validate_user_input(char input)
{
     if (input == '1'){

        }
    if (input == '2'){

        }
    if (input == '3'){

        }
    if (input == '4'){

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

