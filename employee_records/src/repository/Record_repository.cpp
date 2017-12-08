#include "Record_repository.h"

void Record_repository::add_record(const Employee& employee)
{
    ofstream fout;
    vector<Employee> file_content = fill_vector();
    if(!file_content.empty()){
        file_content = remove_duplicate(file_content, employee);
    }
    fout.open("employee_records.txt", ios::out|ios::trunc);
    if (fout.is_open())
    {
        for(unsigned int i = 0; i < file_content.size(); i++)
        {
            fout << file_content[i];
        }
        fout.close();
    }
    else
    {
        /// throw error
    }
}
vector<Employee> Record_repository::remove_duplicate(vector<Employee> file_content, Employee employee)
{
    cout << file_content.size();
    system("pause");
    for (unsigned int i = 0; i < file_content.size(); i++)
    {
        if(employee.getSSN() == file_content[i].getSSN() && employee.getMonth() == file_content[i].getMonth() && employee.getYear() == file_content[i].getYear())
        {
            file_content[i] = employee;
            return file_content;
        }
    }
    file_content.push_back(employee);
    return file_content;
}
vector<Employee> Record_repository::getVector()
{
    return vector_of_records;
}
vector<Employee> Record_repository::fill_vector()
{
    string line;
    ifstream fin;

    fin.open("employee_records.txt");
    if (fin.is_open())
    {

        vector_of_records.clear();
        while(getline(fin, line))
        {
            vector_of_records.push_back(parse_string(line));
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
vector<Employee> Record_repository::vector_filtered_ssn_year(vector<Employee> vector_of_records, string ssn, int year)
{
    vector<Employee> temp;
    for(unsigned int i = 0; i < vector_of_records.size(); i++)
    {
        if(vector_of_records[i].getSSN() == ssn && vector_of_records[i].getYear() == year)
        {
            temp.push_back(vector_of_records[i]);
        }
    }
    return temp;
}
Employee Record_repository::parse_string(string line)
{
    Employee emp;
    int month;
    int year;
    double salary;
    string property = "";
    vector<string> temp;
    for(unsigned int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            temp.push_back(property);
            property = "";
        }
        else
        {
            property += line[i];
        }
    }
    month = atoi(temp[3].c_str());
    year = atoi(temp[4].c_str());
    salary = atof(temp[2].c_str());

    Employee e(temp[0], temp[1], salary, month, year);

    return e;
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
/*void Record_repository::retrieve_record(string ssn)
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
}*/
