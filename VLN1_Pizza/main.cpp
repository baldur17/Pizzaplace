#include <iostream>
#include <stdlib.h>
#include <MainUI.h>
#include <Order.h>


/*///muna taka ut, nota til ad testa;
#include <Pizza.h>
#include <Topping.h>
#include <vector>
#include <Order.h>
#include <Order_repository.h>*/

using namespace std;

int main()
{
    /*///allt � main er eing�ngu til a� pr�fa
    Order_repository o_repo;
    vector<Order> o;
    vector<vector<Topping> > t;
    t = o_repo.fill_topping_order_vector();
    ///t er vector af vectorum af topping
    o = o_repo.fill_order_vector();
    cout << o[0].getPhone_number();
    ///o er vector af orders
    for (unsigned int i = 0; i < o.size(); i++)
    {
        vector<Topping> topping_test;
        Pizza p_test;
        p_test = o[i].getPizza();
        ///n� � pizzu �r staki 0 � order
        p_test.setTopping(t[i]);
        ///set topping � staki 0 � pizzuna
        o[i].setPizza(p_test);
        ///set pizzuna (nuna me� topping) aftur � order
        cout << o[i].getPizza() << endl;
        ///vectorinn o er nuna fylltur af orders me� topping included
        ///seinna topping cout-ast � a�ra linu, �tti ekki a� skipta mali
        ///�vi vi� munum ekki nota cout � pizzu til a� syna a skja
        ///freka cout � akve�na breytu sem vi� viljum t.d cout << "pizza".getPrice() etc
    }
    system("pause");*/
    MainUI mainui;
    mainui.startUI();


    return 0;
}
