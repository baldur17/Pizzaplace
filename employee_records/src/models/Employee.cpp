#include "Employee.h"

Employee::Employee()
{
    name = "";
    ssn = "";
    salary = 0;
    month = 0;
    year = 0;
}
Employee::Employee(string name, string ssn, double salary, int month, int year)
{
    this->name = name;
    this->ssn = ssn;
    this->salary = salary;
    this->month = month;
    this->year = year;
}
ostream& operator << (ostream& out, const Employee& employee)
{
    out << employee.name << " " << employee.ssn << " " << employee.salary << " " << employee.month << " " << employee.year << endl;
    return out;
}
istream& operator >> (istream& in, Employee& employee)
{
    in >> employee.name >> employee.ssn >> employee.salary >> employee.month >> employee.year;
    return in;
}
string Employee::getName()
{
    return this->name;
}
string Employee::getSSN()
{
    return this->ssn;
}
double Employee::getSalary()
{
    return this->salary;
}
int Employee::getMonth()
{
    return this->month;
}
int Employee::getYear()
{
    return this->year;
}
/*istream& operator >> (istream& in, Employee& employee)
{
    //cout << endl;
    //cout << "\tPlease Enter Employee's Name: ";
    in >> employee.name;
    ///getline(in, employee.name);
    //cout << "\tPlease Enter Employee's ssn: ";
    in >> employee.ssn;
    //cout << "\tPlease Enter Employee's salary: ";
    in >> employee.salary;
    //cout << "\tPlease Enter Month(integer): ";
    in >> employee.month;
    //cout << "\tPlease Enter Year(integer): ";
    in >> employee.year;
    return in;
}*/
