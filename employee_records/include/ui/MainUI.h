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
        void recieve_ssn_record(vector<Employee> record);
        string month_name(int month);
    private:
        Employee_service emp_service;
        ///Record_service rec_service;
};

#endif // MAINUI_H
