#include "store.h"


Store::Store(const std::vector< std::shared_ptr<Product>>& _products)
{
    this->all_products = _products;
}

const User& Store::get_current_user() const
{
    return current_user;
}

void Store::log_in()
{
    bool doesUserExist = false;
    std::string username;
    std::string password;
    std::string email;

    std::cout << "Login: " << std::endl;
    std::cout << "Enter username: " << std::endl;
    std::cin >> username;
    std::cout << "Enter password: " << std::endl;
    std::cin >> password;
    std::cout << "Enter your email: " << std::endl;
    std::cin >> email;


    for (int i = 0; i < users.size(); i++)
    {
        if (username == users[i].getUsername() && password == users[i].getPassword())
        {
            current_user = users[i];

            std::cout << std::endl << "Successful login!" << std::endl;

            doesUserExist = true;

            break;
        }
    }

    if (doesUserExist == false) // TODO first user has to be log in before seeing the items 
    {
        std::cout << std::endl << "User not found." << std::endl;
        std::cout << "Please registered first! " << std::endl;
        registration();
    }
}

void Store::registration()
{
    bool doesUserExist = false;

    std::string username;
    std::string password;
    std::string email;

    //TODO some validation 
    std::cout << "Register: " << std::endl;
    std::cout << "Choose username: ";
    std::cin >> username;
    std::cout << "Choose password: ";
    std::cin >> password;
    std::cout << "Enter your email: ";
    std::cin >> email;


    for (int i = 0; i < users.size(); i++)
    {
        if (username == users[i].getUsername() && password == users[i].getPassword() && email == users[i].getEmail())
        {
            doesUserExist = true;

            break;
        }

    }

    if (doesUserExist == true)
    {
        std::cout << "User exist" << std::endl;
        std::cout << std::endl;
    }
    else
        users.push_back(User(username, password, email));
        current_user = User(username, password, email);
}

void Store::print_current_user() const
{
    std::cout << "Current Loged user: " << std::endl;
    current_user.display_intro();
    std::cout << std::endl;
}

void Store::print_users() const
{
    std::cout << "Users list: " << std::endl;

    for (int i = 0; i < users.size(); i++)
    {
        users[i].print();
        std::cout << std::endl;
    }

    std::cout << std::endl;
}


void Store::buy_product()
{
    bool final_order;
    //check if price is zero 
    if (orders.get_products().empty()) {
        std::cout << "Nothing added yet" << std::endl;
    }
    else {
        orders.print_products();
        std::cout << std::endl;
        std::cout << "The final price: " << orders.get_price_order() << std::endl;
        std::cout << "Complete the order(0 to exit, 1 to complete): " << std::endl;

        std::cin >> final_order;
        if (final_order == true)
        {
            std::cout << "Successful purchase" << std::endl;
            std::cout << "Thank you for your order " << current_user.getUsername() << "!" << std::endl;
            orders.clear_order();
        }
    }


    std::cout << std::endl;
}


void Store::remove_product()
{
    bool isItemFound = false;

    std::string _brand;
    std::string _type;
    std::string  _color;

    std::cout << "In order to remove product type its brand , type and color." << std::endl;
    std::cout << "Brand: ";
    std::cin >> _brand;
    std::cout << "Type: ";
    std::cin >> _type;
    std::cout << "Color: ";
    std::cin >> _color;

    for (int i = 0; i < orders.products.size(); i++)
    {
        if (orders.products[i]->getBrand() == _brand && orders.products[i]->getType() == _type && orders.products[i]->getColor() == _color)
        {
            orders.remove_product_from_order(orders.products[i]);
            isItemFound = true;
            break;;
        }
    }

    if (isItemFound == false)
    {
        std::cout << "Item not found." << std::endl;
        return;
    }

    std::cout << std::endl;
}

void Store::add_product()
{
    bool isItemFound = false;

    std::cout << "Enter product type" << std::endl;
    std::cout << "Type: ";
    std::string _type;
    std::cin >> _type;

    for (int i = 0; i < all_products.size(); i++)
    {
        if (all_products[i]->getType() == _type)
        {
            orders.add_product_in_order(all_products[i]);
            isItemFound = true;
            break;;
        }
    }

    if (isItemFound == false)
    {
        std::cout << "Item not found." << std::endl;
        return;
    }
    
    std::cout << std::endl;

}


void Store::get_user_products() const
{
    if (orders.get_products().empty()) {
        std::cout << "Nothing added yet" << std::endl;
    }
    else {
        orders.print_products();
    }

    std::cout << std::endl;
}

void Store::print_available_clothes(std::string filename)
{
    std::vector<Clothes> clothes;
    clothes.resize(10);
    std::ifstream in(filename);
    int recCount = 0;  // keep track of actual number of records

    while (!in.eof() && recCount < 10)
    {
        in >> clothes[recCount].type >> clothes[recCount].brand
            >> clothes[recCount].color >> clothes[recCount].size >> clothes[recCount].price;
        ++recCount;
    }
    in.close();

    std::cout.width(12); std::cout << "Type";
    std::cout.width(10); std::cout << "Brand.";
    std::cout.width(10); std::cout << "Color" ;
    std::cout.width(10); std::cout << "Size" ;
    std::cout.width(10); std::cout << "Price" ;
    std::cout << std::endl;

    for (auto const& i : clothes) {
        i.display_product();
        std::shared_ptr<Product> p(std::make_shared<Clothes>(i));
        all_products.push_back(p);
    }

    std::cout << std::endl;
    
}

void Store::print_available_bags(std::string filename)
{
    std::vector<Bag> bags;
    bags.resize(10);
    std::ifstream in(filename);
    int recCount = 0;  // keep track of actual number of records

    while (!in.eof() && recCount < 10)
    {
        in >> bags[recCount].type >> bags[recCount].brand
            >> bags[recCount].color >> bags[recCount].price;
        ++recCount;
    }
    in.close();

    std::cout.width(12); std::cout << "Type";
    std::cout.width(10); std::cout << "Brand.";
    std::cout.width(10); std::cout << "Color";
    std::cout.width(10); std::cout << "Price";
    std::cout << std::endl;

    for (auto const& i : bags) {
        i.display_product();
        std::shared_ptr<Product> p(std::make_shared<Bag>(i));
        all_products.push_back(p);
    }

    std::cout << std::endl;
}



