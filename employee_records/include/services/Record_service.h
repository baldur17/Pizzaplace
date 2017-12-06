#ifndef RECORD_SERVICE_H
#define RECORD_SERVICE_H
#include "Record_repository.h"
#include "Employee.h"
#include <vector>
#include <stdlib.h>

using namespace std;

class Record_service
{
    public:
        void recieve_record(vector<Employee> vector_of_service, string ssn);
        vector<Employee> getVector();
    private:
        Record_repository record_repo;
};

#endif // RECORD_SERVICE_H
