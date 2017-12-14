#ifndef SALESUI_H
#define SALESUI_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Order_service.h"
#include "Order.h"
#include "Topping.h"
#include "Pizza_service.h"
#include "DrinksService.h"
#include "LocationsService.h"

using namespace std;

class SalesUI
{
    public:
        void startUI();
        char validate_user_input(char input);
        void create_order();
        string pizza_size_string(char size);
        Pizza add_base_pizza();
        Drinks add_drinks();
        Locations add_location();
    private:
        Order_service order_service;

};

#endif // SALESUI_H
