#include "mainUI.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void mainUI::startUI()
{
    //Placeholder nöfn
    char input = '0';
    while(input != '5')
    {
    system("cls");
    cout << endl;
    cout << "\tMAIN MENU" << endl << endl;
    cout << "\t01. MANAGEMENT" << endl << endl;
    cout << "\t02. BAKER" << endl << endl;
    cout << "\t03. SALES" << endl << endl;
    cout << "\t04. DELIVERY" << endl << endl;
    cout << "\t05. EXIT" << endl << endl;
    cout << "\tSelect Your Option <1-X> ";
    cin >> input;
    if (input == '1')
        {
            managementUI managementui;
            managementui.startUI();
        }
    if (input == '2')
        {
            bakerUI bakerui;
            bakerui.startUI();
        }
    if (input == '3')
        {
            salesUI salesui;
            salesui.startUI();
        }
    if (input == '4')
        {
            deliveryUI deliveryui;
            deliveryui.startUI();
        }
    if (input == '5')
        {
            return;
        }
    }
}
