#ifndef RECORD_REPOSITORY_H
#define RECORD_REPOSITORY_H
#include "Record_service.h"
#include <fstream>
#include "Employee.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Record_repository
{
    public:
        void add_record(const Employee& employee);
        void retrieve_record(string ssn);
    private:
        vector<Employee> vector_of_records;
        Record_service record_service;

};

#endif // RECORD_REPOSITORY_H
