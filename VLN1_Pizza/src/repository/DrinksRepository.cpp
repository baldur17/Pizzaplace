#include "DrinksRepository.h"
#include <fstream>

void DrinksRepository::addDrink(const Drinks& drinks) {

    ofstream fout;
    fout.open("drinks.txt", ios::app);
    if (fout.is_open()) {
        fout << drinks;
        fout.close();
    }
}
vector<Drinks> DrinksRepository::fill_locations_vector()
{
    string line;
    ifstream fin;
    fin.open("drinks.txt");
    if (fin.is_open())
    {

        vector_of_drinks.clear();
        while(getline(fin, line))
        {
            vector_of_drinks.push_back(parse_string(line));
        }
        fin.close();
    }
    return vector_of_drinks;
}
Drinks DrinksRepository::parse_string(string line)
{
    vector<string> temp;
    int price;
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
    price = atoi(temp[0].c_str());
    Drinks d(temp[0], temp[1], price);
    return d;
}
