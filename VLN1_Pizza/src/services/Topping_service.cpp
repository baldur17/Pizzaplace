#include "Topping_service.h"

void Topping_service::write_topping(Topping t)
{
    validate_price(t.getPrice());
    t_repository.add_to_file(t);
    ///calla í validate name og price
}
void Topping_service::validate_price(int price)
{
    if(price < 0 || price > 10000)
    {
        throw Invalid_price_exception();
    }
}
void Topping_service::validate_name(string name)
{
    for (unsigned int i = 0; i < name.length(); i++)
    {
        if (!isalpha(name[i]) && !isspace(name[i]))
        {
            throw Invalid_name_exception();
        }
    }
}
