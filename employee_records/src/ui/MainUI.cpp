#include "MainUI.h"


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
            catch (Invalid_name_exception){
                cout << endl;
                cout << "\tInvalid Name!" << endl;
                system("pause");
            }
        }
    if (input == '2')
        {
            string ssn;
            cout << endl;
            cout << "\tEnter Employee's SSN(10 Digits): ";
            cin >> ssn;
            vector<Employee> record;
            try{
            emp_service.validate_ssn(ssn);
            record = emp_service.retrieve_record(ssn);
            recieve_ssn_record(record);
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
            cout << "\tEnter The Year You Wish To Get Records From: ";
            cin >> year;
            vector<Employee> yearly_record;
            try{
            emp_service.validate_ssn(ssn);
            emp_service.validate_year(year);
            yearly_record = emp_service.retrieve_record_for_year(ssn, year);
            total_salary_display(yearly_record);
            cout << endl;
            system("pause");

            }
            catch (Invalid_ssn_exception){
                cout << "Invalid SSN number!" << endl;
                system("pause");
            }
            catch (Invalid_year_exception){
                cout << "Invalid Year!" << endl;
                system("pause");
            }

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
void MainUI::total_salary_display(vector<Employee> yearly_record)
{
    double total_salary;
    for (unsigned int i = 0; i < yearly_record.size(); i++)
    {
        total_salary += yearly_record[i].getSalary();
    }
    cout << "\t" << yearly_record[0].getName() << "'s Yearly Salary Is: " << total_salary << " ISK" << endl;
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
void MainUI::recieve_ssn_record(vector<Employee> record)
{
    for (unsigned int i = 0;i < record.size(); i++)
    {
        month_name(record[i].getMonth());
        cout << endl;
        cout << "Employee's Name:  " << record[i].getName() << endl;
        cout << "Employee's SSN:   " << record[i].getSSN() << endl;
        cout << "Employee's Salary " << record[i].getSalary() << " ISK" << endl;
        cout << "Record For Month: " << month_name(record[i].getMonth()) << endl; ///syna manud ekki tolu hugsanlega
        cout << "Record For Year   " << record[i].getYear() << endl;
    }
    system("pause");
}
string MainUI::month_name(int month)
{
    string name_of_month;
    if(month == 1)
    {
        name_of_month = "January";
        return name_of_month;
    }
    if(month == 2)
    {
        name_of_month = "February";
        return name_of_month;
    }
    if(month == 3)
    {
        name_of_month = "Mars";
        return name_of_month;
    }
    if(month == 4)
    {
        name_of_month = "April";
        return name_of_month;
    }
    if(month == 5)
    {
        name_of_month = "May";
        return name_of_month;
    }
    if(month == 6)
    {
        name_of_month = "June";
        return name_of_month;
    }
    if(month == 7)
    {
        name_of_month = "July";
        return name_of_month;
    }
    if(month == 8)
    {
        name_of_month = "August";
        return name_of_month;
    }
    if(month == 9)
    {
        name_of_month = "September";
        return name_of_month;
    }
    if(month == 10)
    {
        name_of_month = "October";
        return name_of_month;
    }
    if(month == 11)
    {
        name_of_month = "November";
        return name_of_month;
    }
    if(month == 12)
    {
        name_of_month = "December";
        return name_of_month;
    }
    exit(0);
}
