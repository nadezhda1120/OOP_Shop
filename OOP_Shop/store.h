#pragma once
#include <iostream>
#include <fstream>
#include "user.h"
#include "order.h"
#include <memory>
#include <fstream>
#include <sstream>


class Store
{
private:
    std::vector<std::shared_ptr<Product>> all_products;
    Order orders;
    std::vector<User> users;
    User current_user;

public:
    Store() {}; // we use delete in order not to create "empty store"
    Store(const std::vector<std::shared_ptr<Product>>& _products);
    const User& get_current_user() const;

    void log_in();
    void registration();
    void print_current_user() const;
    void print_users() const; // not needed


    void remove_product();
    void add_product();
    void buy_product();

    //void print_products() const;

    void get_user_products() const;

    void print_available_clothes(std::string filename);
    void print_available_bags(std::string filename);
};

