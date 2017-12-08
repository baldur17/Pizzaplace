#ifndef EMPLOYEE_SERVICE_H
#define EMPLOYEE_SERVICE_H
#include <vector>
#include "Employee.h"
#include "Record_repository.h"
#include "Invalid_ssn_exception.h"
#include "Invalid_month_exception.h"
#include "Invalid_salary_exception.h"
#include "Invalid_year_exception.h"
#include "Invalid_name_exception.h"
#include <iostream>

using namespace std;

class Employee_service
{
    public:
        void add_record(Employee& employee);
        vector<Employee> retrieve_record(string ssn);
        vector<Employee> retrieve_record_for_year(string ssn, int year);
        vector<Employee> retrieve_highest_salary();
        void highest_salary(vector<string> highest_salary, vector<Employee> temp);
        void validate_ssn(string ssn);
        void validate_name(string name);
        void validate_salary(double salary);
        void validate_month(int month);
        void validate_year(int year);
    private:
        Record_repository record_repo;
};

#endif // EMPLOYEE_SERVICE_H
