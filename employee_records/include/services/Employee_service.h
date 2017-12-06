#ifndef EMPLOYEE_SERVICE_H
#define EMPLOYEE_SERVICE_H
#include <vector>
#include "Record_repository.h"
#include "Invalid_ssn_exception.h"
#include "Employee.h"
#include <iostream>

using namespace std;

class Employee_service
{
    public:
        void add_record(const Employee& employee);
        void retrieve_record(string ssn);
    private:
        Record_repository record_repo;
};

#endif // EMPLOYEE_SERVICE_H
