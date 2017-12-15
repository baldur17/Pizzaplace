#include "BakerUI.h"

void BakerUI::selectLocation() {
    LocationsService location;
    vector<Locations> l;
    string cityInput, streetInput;
    cout << "\tPlease enter city: ";
    cin >> cityInput;
    cout << "\tPlease enter street: ";
    cin >> streetInput;

    l = location.fetch_location();

    for (unsigned int i = 0; i < l.size(); i++) {
        if (l[i].getCity() == cityInput) {
            if (l[i].getStreet() == streetInput) {
                startUI(cityInput, streetInput);
            }
        }
        //exception
    }
}

void BakerUI::print_orders(string cityInput, string streetInput) {
    vector<Order> o, l;
    vector<Topping> temp;
    Order_service order;
    o = order.retrieve_order_with_topping();

    vector<int> counter;
    for (unsigned int k = 0; k < o.size(); k++){


        if (o[k].getLocation().getCity() == cityInput && o[k].getLocation().getStreet() == streetInput) {
            counter.push_back(k);
            l.push_back(o[k]);
            }
    }
    for (unsigned int i = 0; i < l.size(); i++) {

            if (l[i].getFlag() == 'n' || l[i].getFlag() == 'p') {
                cout << "Pizza size: " << l[i].getPizza().getPizza_size() << endl;
                cout << "Toppings: ";
                temp = l[i].getPizza().getTopping();
                for (unsigned int j = 0; j < temp.size(); j++) {
                        cout << temp[j].getName() << ", ";
                    }
                cout << endl;
                cout << "Flag: " <<l[i].getFlag() << endl;
                char flagInput;
                cout << "\t\tCHANGE FLAG? (y/n) ";
                cin >> flagInput;
                if (flagInput == 'y') {
                        if (l[i].getFlag() == 'n'){
                            o[counter[i]].setFlag('p');
                        }
                        else if(l[i].getFlag() == 'p')
                        {
                            o[counter[i]].setFlag('r');
                        }
                        order.overwrite_order_file(o);
                }
            }
        }
        cout << "\tEnd Of Orders" << endl;


}

//void BakerUI::tagchange_to_file

void BakerUI::startUI(string cityInput, string streetInput) {
    char input = '0';
    while(input != '2') {
        cout << endl;
        cout << "\tBAKER MENU" << endl;
        cout << "\t01. SEE ORDERS TO BAKE" << endl;
        cout << "\t02. BACK" << endl;
        cin >> input;
        system("cls");
        validate_user_input(input, cityInput, streetInput);
    }
}

char BakerUI::validate_user_input (char input, string cityInput, string streetInput) {
    if (input == '1') {
            print_orders(cityInput, streetInput);
    }
    if (input == '2') {
        MainUI mainui;
        mainui.startUI();
    }
    return '0';
}


