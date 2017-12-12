#include "LocationsRepository.h"
#include <fstream>

void LocationsRepository::addLocation(const Locations& location) {

    ofstream fout;
    fout.open("locations.txt", ios::app);
    if (fout.is_open()) {
        fout << location;
        fout.close();
    }
}
