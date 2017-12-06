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
}
void Record_repository::retrieve_record(string ssn)
{
    string str;
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
        /*for(unsigned int i = 0;i < vector_of_records.size();i++)
        {
            ///cout << vector_of_records[i].getName();
            cout << vector_of_records.at(i);
        }
        system("pause");*/
        fin.close();
        record_service.recieve_record(vector_of_records, ssn);
    }
system("pause");
}
/*void Record_repository::retrieve_record()
{
    string str;
    vector<string> temp;
    int counter = 0;
    ifstream fin;
    Employee employee;
    fin.open("employee_records.txt");
    if (fin.is_open())
    {
        vector_of_records.clear();
        while(getline(fin, str, ','))
        {
            vector_of_records.push_back(str);
            counter++;
        }
        for(unsigned int i = 0;i < vector_of_records.size();i++)
        {
            cout << vector_of_records.at(i);
        }
        system("pause");
        fin.close();
    }
}*/
