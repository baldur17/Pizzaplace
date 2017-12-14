#ifndef LOCATIONSSERVICE_H
#define LOCATIONSSERVICE_H

#include "Locations.h"
#include "LocationsRepository.h"

class LocationsService {

    public:
        void addLocation(const Locations& location);
        vector<Locations> fetch_location();

    private:
        LocationsRepository locationsRepo;
};

#endif // LOCATIONSSERVICE_H
