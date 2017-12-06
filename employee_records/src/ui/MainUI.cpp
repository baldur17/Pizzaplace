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
        cout << "\tSelect Your Option <1-X> ";
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
            emp_service.add_record(employee);
        }
    if (input == '2')
        {
            string ssn;
            cout << endl;
            cout << "Enter Employee's SSN(10 Digits): ";
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

        }
    if (input == '4')
        {

        }
    if (input == '5')
        {
            input = '5';
            return input;
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
