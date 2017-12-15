#include "Order_service.h"

vector<Order> Order_service::retrieve_order_with_topping()
{
    vector<Order> order_vector;
    vector<vector<Topping> > topping_vector;
    Order_repository temp;
    order_vector = temp.fill_order_vector();
    topping_vector = temp.fill_topping_order_vector();
    for (unsigned int i = 0; i < topping_vector.size(); i++)
    {
        Pizza p_temp;
        p_temp = order_vector[i].getPizza();
        p_temp.setTopping(topping_vector[i]);
        order_vector[i].setPizza(p_temp);
    }
    return order_vector;
}
void Order_service::add_order_to_file(Order order)
{
    Order_repository repo_temp;
    repo_temp.order_to_file(order);

}
void Order_service::add_topping_to_file(vector<Topping> toppings)
{
    Order_repository repo_temp;
    repo_temp.topping_to_file(toppings);
}
