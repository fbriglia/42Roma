#include "PhoneBook.hpp"

void PhoneBook::print_contact(int x)
{
    if (x > 7 || x < 0)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    std::cout << "First Name: " << Contacts[x].getfirst_name() << std::endl;
    std::cout << "Last Name: " << Contacts[x].getlast_name() << std::endl;
    std::cout << "Nickname: " << Contacts[x].getnickname() << std::endl;
    std::cout << "Phone Number: " << Contacts[x].getphone_number() << std::endl;
    std::cout << "Darkest Secret: " << Contacts[x].getdarkest_secret() << std::endl;

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