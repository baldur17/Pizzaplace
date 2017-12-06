#include "Record_repository.h"

void Record_repository::add_record(const Employee& employee)
{
    ofstream fout;
    fout.open("employee_records.txt", ios::app);
    if (fout.is_open())
    {
        fout << employee;
        fout.close();
    }
    else
    {
        /// throw error
    }
    ///calla í fill_vector
    ///calla í remove duplicates
}
void Record_repository::retrieve_record(string ssn)
{
    ifstream fin;
    fin.open("employee_records.txt");
    if (fin.is_open())
    {
        vector_of_records.clear();
        while(!fin.eof())
        {
            Employee employee;
            fin >> employee;
            if(fin.eof())
            {
                break;
            }
            vector_of_records.push_back(employee);
        }
        fin.close();
        ///record_service.recieve_record(vector_of_records, ssn);
    }
}
vector<Employee> Record_repository::getVector()
{
    return vector_of_records;
}
vector<Employee> Record_repository::fill_vector()
{
    ifstream fin;
    fin.open("employee_records.txt");
    if (fin.is_open())
    {
        vector_of_records.clear();
        while(!fin.eof())
        {
            Employee employee;
            fin >> employee;
            if(fin.eof())
            {
                break;
            }
            vector_of_records.push_back(employee);
        }
        fin.close();
    }
    return vector_of_records;
}
vector<Employee> Record_repository::vector_filtered_ssn(vector<Employee> vector_of_records, string ssn)
{
    vector<Employee> temp;
    for(unsigned int i = 0; i < vector_of_records.size(); i++)
    {
        if(vector_of_records[i].getSSN() == ssn)
        {
            temp.push_back(vector_of_records[i]);
        }
    }
    return temp;
}
/*void Record_repository::retrieve_record(string ssn)
{
    string str;
    ifstream fin;
    Employee employee;
    fin.open("employee_records.txt");
    if (fin.is_open())
    {
        vector_of_records.clear();
        while(getline(fin, str, ','))
        {

            system("pause");
            //vector_of_records.push_back(str);
        }
        fin.close();
    }
    //record_service.recieve_record(vector_of_records, ssn);
}*/
