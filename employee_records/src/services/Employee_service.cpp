#include "Employee_service.h"

void Employee_service::add_record(const Employee& employee)
{
    ///validate
    record_repo.add_record(employee);
}
void Employee_service::retrieve_record(string ssn)
{
    if (ssn.length() != 10)
    {
        ///throw exception
        throw Invalid_ssn_exception();
    }
    ///validate 10 digit string ssn
    for (unsigned int i = 0; i < ssn.length(); i++)
    {
        if(!isdigit(ssn[i]))
        {
            ///throw exception
            throw Invalid_ssn_exception();
        }
    }
    record_repo.retrieve_record(ssn);
}
