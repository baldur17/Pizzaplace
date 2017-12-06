#include "Record_service.h"

vector<Employee> Record_service::recieve_record(vector<Employee> vector_of_service, string ssn)
{
    ///lesa ur vector record med tessu ssn
    vector<Employee> temp;
    for(unsigned int i = 0; i < vector_of_service.size(); i++)
    {
        if(vector_of_service[i].getSSN() == ssn)
        {
            temp.push_back(vector_of_service[i]);
            cout << temp[i];
        }
    }
    system("pause");
}
