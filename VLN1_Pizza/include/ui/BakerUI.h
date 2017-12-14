#ifndef BAKERUI_H
#define BAKERUI_H
#include <Order.h>
#include <Order_service.h>
#include <Locations.h>
#include <LocationsService.h>
#include "MainUI.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;


class BakerUI
{
    public:
        void startUI(string cityInput, string streetInput);
        void selectLocation();
        char validate_user_input(char input, string cityInput, string streetInput);
        void print_orders(string cityInput, string streetInput);

    private:
};

#endif // BAKERUI_H
