#ifndef RECORD_REPOSITORY_H
#define RECORD_REPOSITORY_H
#include "Employee.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>

using namespace std;

class Record_repository
{
    public:
        void add_record(const Employee& employee);
        void retrieve_record(string ssn);
        vector<Employee> fill_vector();
        vector<Employee> getVector();
        vector<Employee> vector_filtered_ssn(vector<Employee> vector_of_records, string ssn);
        vector<Employee> vector_filtered_ssn_year(vector<Employee> vector_of_records, string ssn, int year);
        Employee parse_string(string property);
        vector<Employee> remove_duplicate(vector<Employee> file_content, Employee employee);
    private:
        vector<Employee> vector_of_records;
        ///Record_service record_service;

};

#endif // RECORD_REPOSITORY_H
