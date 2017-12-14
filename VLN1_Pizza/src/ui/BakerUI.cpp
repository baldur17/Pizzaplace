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

    for (unsigned int k = 0; k < o.size(); k++){
        if (o[k].getLocation().getCity() == cityInput && o[k].getLocation().getStreet() == streetInput) {
            l.push_back(o[k]);
            for (unsigned int i = 0; i < l.size(); i++) {
                cout << "Pizza size: " << l[i].getPizza().getPizza_size() << endl;
                cout << "Toppings: ";
                temp = l[i].getPizza().getTopping();
                for (unsigned int j = 0; j < temp.size(); j++) {
                    cout << temp[j].getName() << ", ";
                }
                cout << endl;
            }
        }
    }
}
void BakerUI::startUI(string cityInput, string streetInput) {
    char input = '0';
    while(input != '2') {
        cout << endl;
        cout << "\tBAKER MENU" << endl;
        cout << "\t01. SEE ORDERS TO BAKE" << endl;
        cout << "t\02. BACK" << endl;
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

}
