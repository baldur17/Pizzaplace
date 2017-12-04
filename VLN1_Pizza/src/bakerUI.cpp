#include "bakerUI.h"

using namespace std;

void bakerUI::startUI()
//placeholder nöfn á öllu
{
    char input = '0';
    while(input == '0')
    {
    system("cls");
    cout << "\tBAKER OPTIONS" << endl << endl;
    cout << "\t01. " << endl << endl;
    cout << "\t02. " << endl << endl;
    cout << "\t03. " << endl << endl;
    cout << "\t04. RETURN" << endl << endl;
    cout << "\tSelect Your Option <1-X>" << endl << endl;
    cin >> input;
    if (input == '1')
        {
            return;
        }
    if (input == '4')
        {
            return;
        }
    }
}

