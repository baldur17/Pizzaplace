#include "MainUI.h"

void MainUI::startUI()
{
    char input = '0';
    while(input != '5')
    {
        cout << endl;
        cout << "\tMAIN MENU" << endl << endl;
        cout << "\t01. MANAGEMENT" << endl << endl;
        cout << "\t02. SALES" << endl << endl;
        cout << "\t03. BAKER" << endl << endl;
        cout << "\t04. DELIVERY" << endl << endl;
        cout << "\t05. EXIT" << endl << endl;
        cout << "\tSelect Your Option <1-5> ";
        cin >> input;
        system("cls");
        validate_user_input(input);
    }
}
///Þetta function validate-ar hvaða UI user vill fara inn í
///velur ManagementUI,SalesUI etc.
char MainUI::validate_user_input(char input)
{
    if (input == '1'){
            ManagementUI managementui;
            managementui.startUI();
        }
    if (input == '2'){
            SalesUI salesui;
            salesui.startUI();

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
