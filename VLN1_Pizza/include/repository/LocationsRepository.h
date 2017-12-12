#ifndef LOCATIONSREPOSITORY_H
#define LOCATIONSREPOSITORY_H
#include "Locations.h"
#include <fstream>
#include <vector>
#include <cstdlib>


class LocationsRepository
{
    public:
        void addLocation(const Locations& location);
        vector<Locations> fill_locations_vector();
        Locations parse_string(string line);
    private:
        vector<Locations> vector_of_locations;
};

#endif // LOCATIONSREPOSITORY_H
