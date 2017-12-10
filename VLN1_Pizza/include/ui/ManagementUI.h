#ifndef MANAGEMENTUI_H
#define MANAGEMENTUI_H
#include <Topping.h>
#include <Topping_service.h>
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
    private:
        Topping_service t_service;
};

#endif // MANAGEMENTUI_H
