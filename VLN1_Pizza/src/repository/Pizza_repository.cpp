#include "Pizza_repository.h"

void Pizza_repository::add_to_file(Pizza p)
{
    ofstream fout;

    fout.open("base_pizza.txt", ios::app);
    if(fout.is_open())
    {
        fout << p;
    }
    fout.close();
}
vector<Pizza> Pizza_repository::fill_basepizza_vector()
{
    string line;
    ifstream fin;
    fin.open("base_pizza.txt");
    if (fin.is_open())
    {

        vector_of_basepizza.clear();
        while(getline(fin, line))
        {
            vector_of_basepizza.push_back(parse_string(line));
        }
        fin.close();
    }
    return vector_of_basepizza;
}
Pizza Pizza_repository::parse_string(string line)
{
    vector<string> temp;
    int price;
    char size;
    string property = "";
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
    price = atoi(temp[1].c_str());
    size = temp[0][0];
    Pizza p(size, price);
    return p;
}
