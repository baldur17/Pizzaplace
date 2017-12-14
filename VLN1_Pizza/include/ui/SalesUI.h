#ifndef SALESUI_H
#define SALESUI_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <Order_service.h>
#include <Order.h>
#include <Topping.h>

using namespace std;

class SalesUI
{
    public:
        void startUI();
        char validate_user_input(char input);
    private:
        Order_service order_service;

};

#endif // SALESUI_H
