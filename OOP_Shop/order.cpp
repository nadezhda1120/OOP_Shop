#include "order.h"

Order::Order()
{
    price_of_order = 0;
}


void Order::print_products() const
{
    for (int i = 0; i < products.size(); i++)
    {
        products[i]->print();
    }
}

void Order::remove_product_from_order(const std::shared_ptr<Product>& item)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i]->getType() == item->getType() && products[i]->getBrand() == item->getBrand()
            && products[i]->getPrice() == item->getPrice() && products[i]->getColor() == item->getColor())
        {
            this->products.erase(products.begin() + i);
            price_of_order -= item->getPrice();
        }
    }

}

void Order::add_product_in_order(const std::shared_ptr<Product>& item)
{
    products.push_back((item));
    price_of_order += item->getPrice();

}

const float Order::get_price_order() const
{
    return price_of_order;
}

const std::vector<std::shared_ptr<Product>> Order::get_products() const
{
    return this->products;
}

void Order::clear_order()
{
    products.clear();
}
