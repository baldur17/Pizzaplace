#include "Pizza_service.h"

void Pizza_service::write_pizza(Pizza p)
{
    validate_size(p.getPizza_size());
    p_repo.add_to_file(p);
}
void Pizza_service::validate_size(char size)
{
    if (size == 's' || size == 'm' || size == 'l'){

    }
    else{
        throw Invalid_pizza_size_exception();
    }
    ///a eftir að implementa að remova duplicates
}
