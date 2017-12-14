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
vector<Pizza> Pizza_service::fetch_base_pizza()
{
    vector<Pizza> p;
    p = p_repo.fill_basepizza_vector();
    return p;
}
