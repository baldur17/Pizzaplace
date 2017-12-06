#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>

using namespace std;

class Employee
{
    public:
        Employee();
        Employee(string name, string ssn, double salary, int month, int year);
        friend ostream& operator << (ostream& out, const Employee& employee);
        friend istream& operator >> (istream& in, Employee& employee);
        string getName();
        string getSSN();
        double getSalary();
        int getMonth();
        int getYear();
    private:
        string name;
        string ssn;
        double salary;
        int month;
        int year;
};

#endif // EMPLOYEE_H
