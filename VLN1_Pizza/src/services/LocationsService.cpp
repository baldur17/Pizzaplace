#include "LocationsService.h"
#include <ctype.h>

void LocationsService::addLocation(const Locations& location) {
    locationsRepo.addLocation(location);
}
