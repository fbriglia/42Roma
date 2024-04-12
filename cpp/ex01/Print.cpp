#include "PhoneBook.hpp"

void PhoneBook::print_contact(int x)
{
    if (x > 7 || x < 0)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    std::cout << "First Name: " << Contacts[x].first_name << std::endl;
    std::cout << "Last Name: " << Contacts[x].last_name << std::endl;
    std::cout << "Nickname: " << Contacts[x].nickname << std::endl;
    std::cout << "Phone Number: " << Contacts[x].phone_number << std::endl;
    std::cout << "Darkest Secret: " << Contacts[x].darkest_secret << std::endl;

}

void print_details(string str)
{
    int diff = 10 - str.length();
    if (diff > 0)
    {
        for (int i = 0; i < diff; i++)
            std::cout << " ";
        std::cout << str << "| ";
    }
    else
    {
        std::cout << str.substr(0, 9) << ".| ";
    }
}