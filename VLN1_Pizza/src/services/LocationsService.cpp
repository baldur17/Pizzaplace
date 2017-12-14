#include "LocationsService.h"
#include <ctype.h>

void LocationsService::addLocation(const Locations& location) {
    locationsRepo.addLocation(location);
}

vector<Locations> LocationsService::fetch_location() {

return locationsRepo.fill_locations_vector();
}

