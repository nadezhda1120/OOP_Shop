#include <iostream>
#include "store.h"
#include <algorithm>

#define FILE_NAME_CLOTHES "clothes.dat"
#define FILE_NAME_BAGS "bags.dat"

using namespace std;

int main()
{
    Store store;
    
    int choice;
    std::cout << "--------------WELCOME----------------" << std::endl;
    do
    {
        cout << "Choose one of the options" << endl;
        cout << endl;
        cout << " 1- Register" << endl;
        cout << " 2- Log in " << endl;
        cout << " 3- See clothes " << endl;
        cout << " 4- See bags " << endl;
        cout << " 5- Add product " << endl;
        cout << " 6- Remove product " << endl;
        cout << " 7- User products " << endl;
        cout << " 8- Buy products " << endl;
        
        cout << endl;
        
        cout << " Enter your choice " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            store.registration();
            std::cout << std::endl;
            store.print_current_user();
            break;
        case 2:
            store.log_in();
            store.print_current_user();
            store.print_users();
            break;
        case 3:
            store.print_available_clothes(FILE_NAME_CLOTHES);
            break;
        case 4:
            store.print_available_bags(FILE_NAME_BAGS);
            break;
        case 5:
            store.add_product();
            break;
        case 6:
            store.remove_product();
            break;
        case 7:
            store.get_user_products();
            break;
        case 8:
            store.buy_product();
            break;
        default:
            cout << "Wrong input!" << endl;
            break;

        }
    } while (choice != 0);
}