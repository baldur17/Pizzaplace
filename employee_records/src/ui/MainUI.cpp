#include "MainUI.h"
#include "Employee.h"
#include "Employee_service.h"
#include <iostream>
#include <string>

void MainUI::startUI()
{
    char input = '0';
    while(input != '5')
    {
        system("cls");
        cout << endl;
        cout << "\tMAIN MENU" << endl << endl;
        cout << "\t01. ADD A SALARY RECORD" << endl << endl;
        cout << "\t02. RETRIEVE SALARY RECORD FOR EMPLOYEE" << endl << endl;
        cout << "\t03. GET YEARLY SALARY FOR EMPLOYEE" << endl << endl;
        cout << "\t04. GET HIGHEST PAID EMPLOYEE" << endl << endl;
        cout << "\t05. EXIT" << endl << endl;
        cout << "\tSelect Your Option <1-5> ";
        cin >> input;
        validate_user_input(input);
    }
}
char MainUI::validate_user_input(char& input)
{
    system("cls");
    if (input == '1')
        {
            Employee employee;
            employee = write_employee();
            try{
            emp_service.add_record(employee);
            }
            catch (Invalid_month_exception){
                cout << endl;
                cout << "\tInvalid Month!" << endl;
                system("pause");
            }
            catch (Invalid_ssn_exception){
                cout << endl;
                cout << "\tInvalid SSN number!" << endl;
                system("pause");
            }
            catch (Invalid_year_exception){
                cout << endl;
                cout << "\tInvalid Year!" << endl;
                system("pause");
            }
            catch (Invalid_salary_exception){
                cout << endl;
                cout << "\tInvalid Salary!" << endl;
                system("pause");
            }
        }
    if (input == '2')
        {
            string ssn;
            cout << endl;
            cout << "\tEnter Employee's SSN(10 Digits): ";
            cin >> ssn;
            try{
            emp_service.retrieve_record(ssn);
            }
            catch (Invalid_ssn_exception){
                cout << "Invalid SSN number!" << endl;
                system("pause");
            }

        }
    if (input == '3')
        {
            string ssn;
            int year;
            cout << endl;
            cout << "\tEnter Employee's SSN(10 digits): ";
            cin >> ssn;
            cout << "Enter The Year You Wish To Get Records From: ";
            cin >> year;
        }
    if (input == '4')
        {

        }
    if (input == '5')
        {
            exit(0);
        }
    return 0;
}
Employee MainUI::write_employee()
{
    string name;
    string ssn;
    double salary;
    int month, year;


    cout << endl;
    cout << "\tPlease Enter Employee's Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "\tPlease Enter Employee's ssn: ";
    cin >> ssn;
    cout << "\tPlease Enter Employee's salary: ";
    cin >> salary;
    cout << "\tPlease Enter Month(integer): ";
    cin >> month;
    cout << "\tPlease Enter Year(integer): ";
    cin >> year;
    return Employee(name, ssn, salary, month, year);
}
void recieve_ssn_record(vector<Employee> record)
{
    for (unsigned int i = 0;i < record.size(); i++)
    {
        cout << endl;
        cout << "Employee's Name:  " << record[i].getName();
        cout << "Employee's SSN:   " << record[i].getSSN();
        cout << "Employee's Salary " << record[i].getSalary();
        cout << "Record For Month: " << record[i].getMonth(); ///syna manud ekki tolu hugsanlega
        cout << "Record For Year   " << record[i].getYear();
        cout << endl;
        system("pause");
    }
}
/*string MainUI::month_name(int month)
{
    if(month == 1)
    {
        month = "January";
        return month;
    }
}*/
