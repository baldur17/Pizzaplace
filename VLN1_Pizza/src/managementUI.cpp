#include "managementUI.h"
using namespace std;
void managementUI::startUI()
//placeholder n�fn/input
//beinagrind fyrir ui
{
    char input = '0';
    while(input == '0')
    {
    system("cls");
    cout << "================================" << endl;
    cout << "\tMANAGEMENT OPTIONS" << endl << endl;
    cout << "\t01. Add Topping To System" << endl << endl;
    cout << "\t02. RETURN" << endl << endl; //Fara til baka � main menu, .02 placeholder , �tti a� vera ne�st
    cout << "\tSelect Your Option <1-X>" << endl << endl;
    cout << "================================" << endl;
    cin >> input;
    if (input == '1')
        {
            //�akve�i� function
        }
    if (input == '2')
        {
            return;
            //return e�a kalla aftur � mainUI;
        }
    }
}
