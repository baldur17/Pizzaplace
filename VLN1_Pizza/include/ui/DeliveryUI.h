#ifndef DELIVERYUI_H
#define DELIVERYUI_H
#include <stdlib.h>
#include <iostream>
#include <string>
#include "LocationsService.h"
#include "Order_service.h"

class DeliveryUI
{
    public:
        void startUI(Locations l);
        void view_order(Locations l);
        char validate_user_input(char input, Locations l);
        void select_location();
        string order_status(char flag);
        string pizza_size(char size);
        void change_flag(Locations l);
    private:
};

#endif // DELIVERYUI_H
