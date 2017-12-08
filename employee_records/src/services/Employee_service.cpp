#include "Employee_service.h"

void Employee_service::add_record( Employee& employee)
{
    validate_ssn(employee.getSSN());
    validate_month(employee.getMonth());
    validate_year(employee.getYear());
    validate_salary(employee.getSalary());

    record_repo.add_record(employee);
}
vector<Employee> Employee_service::retrieve_record(string ssn)
{
    vector<Employee> temp;
    ///recieve record i record_service;
    temp = record_repo.fill_vector();
    return record_repo.vector_filtered_ssn(temp, ssn);
}
vector<Employee> Employee_service::retrieve_record_for_year(string ssn, int year)
{
    vector<Employee> temp;
    temp = record_repo.fill_vector();
    return record_repo.vector_filtered_ssn_year(temp, ssn, year);
}
/*void Employee_service::retrieve_record_2(string ssn, int year)
{
    validate_ssn(ssn);
    validate_year(year);
    record_repo.retrieve_record(ssn);
}*/
void Employee_service::validate_ssn(string ssn)
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
}
void Employee_service::validate_month(int month)
{
    if (month < 1 || month > 12)
    {
        throw Invalid_month_exception();
    }
}
void Employee_service::validate_year(int year)
{
    if (year < 2000 || year > 2017)
    {
        throw Invalid_year_exception();
    }
}
void Employee_service::validate_salary(double salary)
{
    if (salary < 0 || salary > 10000000)
    {
        throw Invalid_salary_exception();
    }
}
