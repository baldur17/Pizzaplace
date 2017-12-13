#include "LocationsRepository.h"
#include <fstream>

void LocationsRepository::addLocation(const Locations& location) {

    ofstream fout;
    fout.open("locations.txt", ios::app);
    if (fout.is_open()) {
        fout << location << endl;
        fout.close();
    }
}
vector<Locations> LocationsRepository::fill_locations_vector()
{
    string line;
    ifstream fin;
    fin.open("locations.txt");
    if (fin.is_open())
    {

        vector_of_locations.clear();
        while(getline(fin, line))
        {
            vector_of_locations.push_back(parse_string(line));
        }
        fin.close();
    }
    return vector_of_locations;
}
Locations LocationsRepository::parse_string(string line)
{
    vector<string> temp;
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

    Locations l(temp[0], temp[1]);
    return l;
}
