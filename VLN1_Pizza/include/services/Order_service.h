#ifndef ORDER_SERVICE_H
#define ORDER_SERVICE_H

#include <vector>
#include <Order.h>
#include <Order_repository.h>
#include <Topping.h>

class Order_service
{
    public:
        vector<Order> retrieve_order_with_topping();
        void add_order_to_file(Order order);
    private:
        Order_repository order_repo;

};

#endif // ORDER_SERVICE_H
