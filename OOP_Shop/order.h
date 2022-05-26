#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clothes.h"
#include "bag.h"
#include <memory>


class Order
{
private:
    std::vector<std::shared_ptr<Product>> products;////ShopingCardProducts;
    float price_of_order;

public:
    Order();

    void print_products() const;
    void remove_product_from_order(const std::shared_ptr<Product>& item);
    void add_product_in_order(const std::shared_ptr<Product>& item);

    const float get_price_order() const;

    const std::vector<std::shared_ptr<Product>> get_products() const;
    void  clear_order();

    friend class Store;
};