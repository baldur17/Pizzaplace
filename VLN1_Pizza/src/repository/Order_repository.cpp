#include "Order_repository.h"

void Order_repository::order_to_file(Order o)
{
    ofstream fout;
    fout.open("order.txt", ios::app);
    if(fout.is_open()){
        fout << o;
    }
    fout.close();
}
void Order_repository::topping_to_file(vector<Topping> t)
{
    ofstream fout;
    fout.open("topping_order.txt", ios::app);
    if(fout.is_open()){
        for(unsigned int i = 0; i < t.size(); i++)
        {
            fout << t[i];
        }
        fout << endl;
    }
    fout.close();
}
vector<vector<Topping> > Order_repository::fill_topping_order_vector()
{
    string line;
    ifstream fin;
    fin.open("topping_order.txt");
    vector<vector<Topping> > t;
    if (fin.is_open())
    {

        vector_of_topping_order.clear();
        while(getline(fin, line))
        {
            //vector_of_topping_order.push_back(parse_topping_string(line));
            vector<Topping> temp_topping_storage;
            temp_topping_storage = parse_topping_string(line);
            //for (unsigned int i = 0; i < temp_topping_storage.size(); i++)
            //{
                vector<Topping> top;
                top = temp_topping_storage;
                t.push_back(top);
            //}
        }
        fin.close();
    }
    return t;
}
vector<Topping> Order_repository::parse_topping_string(string line)
{
    vector<string> temp;
    vector<Topping> toppings;
    int price;
    string property = "";
    int counter = 0;
    for (unsigned int j = 0; j < line.length(); j++)
    {
        if(line[j] == ',')
        {
            counter++;
        }
    }
    int topcnt = counter / 2;
    for(unsigned int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            temp.push_back(property);
            property = "";
        }
        else
        {
            property += line[i];
        }
    }
    for(int k = 0; k < (topcnt * 2); k += 2)
    {
        price = atoi(temp[1 + k].c_str());
        Topping t(temp[0 + k], price);
        toppings.push_back(t);
    }
    return toppings;

}
vector<Order> Order_repository::fill_order_vector()
{
    string line;
    ifstream fin;
    fin.open("order.txt");
    if (fin.is_open())
    {

        vector_of_order.clear();
        while(getline(fin, line))
        {
            vector_of_order.push_back(parse_string(line));
        }
        fin.close();
    }
    return vector_of_order;
}
Order Order_repository::parse_string(string line)
{
    vector<string> temp;
    Pizza temp_pizza;
    int base_price;
    int drink_price;
    char flag;
    string property = "";
    for(unsigned int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            temp.push_back(property);
            property = "";
        }
        else
        {
            property += line[i];
        }
    }
    temp_pizza.setPizza_size(temp[0][0]);
    base_price = atoi(temp[1].c_str());
    temp_pizza.setSize_price(base_price);
    drink_price = atoi(temp[4].c_str());


   /* vector<Topping> topping_vector;
    int counter = 0;

    for (unsigned int j = 0; j <= topcnt; j += 2)
    {
        Topping t(temp[2 + j], temp[2 + j + 1])
        topping_vector.push_back()

    }*/
    ///brand = temp[2]
    ///size(drink) = temp[3]
    ///city = temp[5]
    ///street = temp[6]
    ///flag = temp[7][0]
    flag = temp[7][0];
    Locations l(temp[5], temp[6]);
    Drinks d(temp[2], temp[3], drink_price);
    Order o(temp_pizza, d, l, flag, temp[8]);

    return o;
}
vector<Topping> Order_repository::getVector_of_topping_order()
{
    return vector_of_topping_order;
}
