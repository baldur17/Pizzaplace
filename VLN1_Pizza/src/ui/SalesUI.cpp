#include "SalesUI.h"

void SalesUI::startUI()
{
    char input = '0';
    while(input != '5')
    {
        cout << endl;
        cout << "\tSALES MENU" << endl << endl;
        cout << "\t01. PLACEHOLDER" << endl << endl;
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
