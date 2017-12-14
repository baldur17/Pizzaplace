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
    /*///allt í main er eingöngu til að prófa
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
        ///næ í pizzu úr staki 0 í order
        p_test.setTopping(t[i]);
        ///set topping í staki 0 í pizzuna
        o[i].setPizza(p_test);
        ///set pizzuna (nuna með topping) aftur í order
        cout << o[i].getPizza() << endl;
        ///vectorinn o er nuna fylltur af orders með topping included
        ///seinna topping cout-ast í aðra linu, ætti ekki að skipta mali
        ///þvi við munum ekki nota cout á pizzu til að syna a skja
        ///freka cout á akveðna breytu sem við viljum t.d cout << "pizza".getPrice() etc
    }
    system("pause");*/
    MainUI mainui;
    mainui.startUI();


    return 0;
}
