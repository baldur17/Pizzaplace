#ifndef MANAGEMENTUI_H
#define MANAGEMENTUI_H
#include "Topping.h"
#include "Topping_service.h"
#include "Invalid_price_exception.h"
#include "Pizza.h"
#include "Pizza_service.h"

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class ManagementUI
{
    public:
        void startUI();
        char validate_user_input(char input);
        Topping create_topping();
        Pizza create_pizza();
    private:
        Topping_service t_service;
        Pizza_service p_service;
};

#endif // MANAGEMENTUI_H
