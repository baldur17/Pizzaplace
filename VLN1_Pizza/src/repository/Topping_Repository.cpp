#include "Topping_Repository.h"
void Topping_Repository::add_to_file(Topping t)
{
    ///Þetta function getur ekki lesið inn ef file er empty, en replace-ar duplicates;
    ofstream fout;
    vector<Topping> temp;
    temp = fill_topping_vector();
    temp = remove_duplicate(t, temp);
    fout.open("Topping.txt", ios::trunc);
    if(fout.is_open())
    {
        for(unsigned int i = 0; i < temp.size(); i++){
            fout << temp[i];
            }
    }
    fout.close();
}
vector<Topping> Topping_Repository::remove_duplicate(Topping t, vector<Topping> top)
{
    for (unsigned int i = 0; i < top.size(); i++){
        if(t.getName() == top[i].getName()){
            top[i] = t;
            return top;
        }
    }
    top.push_back(t);
    return top;
}
vector<Topping> Topping_Repository::fill_topping_vector()
{
    string line;
    ifstream fin;
    fin.open("Topping.txt");
    if (fin.is_open())
    {

        vector_of_topping.clear();
        while(getline(fin, line))
        {
            vector_of_topping.push_back(parse_string(line));
        }
        fin.close();
    }
    return vector_of_topping;
}
Topping Topping_Repository::parse_string(string line)
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
    price = atoi(temp[1].c_str());
    Topping t(temp[0], price);
    return t;
}
