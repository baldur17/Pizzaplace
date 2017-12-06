#ifndef MAINUI_H
#define MAINUI_H
#include "Employee_service.h"
#include <stdlib.h>
#include "Employee.h"
#include <string>

using namespace std;

class MainUI
{
    public:
        void startUI();
        char validate_user_input(char &input);
        Employee write_employee();
    private:
        Employee_service emp_service;
};

#endif // MAINUI_H
