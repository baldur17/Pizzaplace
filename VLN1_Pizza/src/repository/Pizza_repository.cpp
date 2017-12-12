#include "Pizza_repository.h"

void Pizza_repository::add_to_file(Pizza p)
{
    ofstream fout;
    vector<Pizza> temp;
    temp = fill_basepizza_vector();
    temp = remove_duplicate(p, temp);
    fout.open("base_pizza.txt", ios::trunc);
    if(fout.is_open())
    {
        for(unsigned int i = 0; i < temp.size(); i++){
            fout << temp[i];
            }
    }
    fout.close();
}
vector<Pizza> Pizza_repository::remove_duplicate(Pizza p, vector<Pizza> p_vector)
{
    for (unsigned int i = 0; i < p_vector.size(); i++){
        if(p.getPizza_size() == p_vector[i].getPizza_size()){
            p_vector[i] = p;
            return p_vector;
        }
    }
    p_vector.push_back(p);
    return p_vector;
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
