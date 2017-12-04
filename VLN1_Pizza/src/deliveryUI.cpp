#include "deliveryUI.h"

using namespace std;

void deliveryUI::startUI()
{
    char input = '0';
    while(input == '0')
    {
    system("cls");
    cout << "===========================" << endl;
    cout << "\tSALES OPTIONS" << endl << endl;
    cout << "\t01. " << endl << endl;
    cout << "\t02. RETURN" << endl << endl; //Fara til baka í main menu, .02 placeholder , ætti að vera neðst
    cout << "\tSelect Your Option <1-X>" << endl << endl;
    cout << "===========================" << endl;
    cin >> input;
    if (input == '1')
        {
            //óakveðið function
        }
    if (input == '2')
        {
            return;
            //return eða kalla aftur í mainUI;
        }
    }
}
