#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

void PhoneBook::search_contact()
{
    string ind;
    int x ;

    if (index == 0)
        return;
    if (index < 8)
        x = index;
    else
        x = 8;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 8; j++)
                std::cout << " ";
        std::cout << i+1 << "| ";
        print_details(Contacts[i].getfirst_name());
        print_details(Contacts[i].getlast_name());
        print_details(Contacts[i].getnickname());
        std::cout << std::endl;
    }
    std::cout << "Enter index: ";
    std::cin >> ind;
    if (ind.length() > 1 || ind[0] <= '0' || ind[0] > '8' )
    {
        std::cout << "WRONG INDEX" << std::endl;
        std::cin.ignore();
        return;
    }
    if (ind[0] <= index+'0')
        print_contact(ind[0]-'0' - 1);
    else
        std::cout << "no index" << std::endl;
    std::cin.ignore();

}

int Contact::check_empty()
{
    if (first_name.empty())
        return 1;
    if (last_name.empty())
        return 1;
    if (nickname.empty())
        return 1;
    if (phone_number.empty())
        return 1;
    if (darkest_secret.empty())
        return 1;
    return 0;
}

void Contact::add_contact()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkest_secret);
}

