#ifndef LOCATIONSSERVICE_H
#define LOCATIONSSERVICE_H

#include "Locations.h"
#include "LocationsRepository.h"

class LocationsService {

    public:
        void addLocation(const Locations& location);

    private:
        LocationsRepository locationsRepo;
};

#endif // LOCATIONSSERVICE_H
