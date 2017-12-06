#ifndef RECORD_SERVICE_H
#define RECORD_SERVICE_H
#include <vector>
#include <Employee.h>
#include <stdlib.h>

using namespace std;

class Record_service
{
    public:
        vector<Employee> recieve_record(vector<Employee> vector_of_service, string ssn);
    private:
};

#endif // RECORD_SERVICE_H
