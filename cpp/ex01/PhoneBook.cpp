#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}

Contact::Contact(){}

void PhoneBook::search_contact()
{
    int ind;
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
        print_details(Contacts[i].first_name);
        print_details(Contacts[i].last_name);
        print_details(Contacts[i].nickname);
        std::cout << std::endl;
    }
    std::cout << "Enter index: ";
    std::cin >> ind;
    if (ind <= index)
        print_contact(ind - 1);
    else
        std::cout << "no index" << std::endl;
    std::cin.ignore();

}

int Contact::check_empty()
{
    if (first_name.empty())
        return 1;
    if (this->last_name.empty())
        return 1;
    if (this->nickname.empty())
        return 1;
    if (this->phone_number.empty())
        return 1;
    if (this->darkest_secret.empty())
        return 1;
    return 0;
}

void Contact::add_contact()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, this->first_name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, this->last_name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, this->nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, this->phone_number);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, this->darkest_secret);
}

int main()
{
    PhoneBook   PhoneBook;
    string      command;

    PhoneBook.contact_count = 0;
    PhoneBook.index = 0;
    while(1)
    {
        if (PhoneBook.contact_count == 8)
            PhoneBook.contact_count = 0;
        std::cout << "Enter Command: ";
        std::getline(std::cin, command);
        if (command == "EXIT")
            break;
        if (command == "ADD")
        {
            PhoneBook.Contacts[PhoneBook.contact_count].add_contact();
            if (PhoneBook.Contacts[PhoneBook.contact_count].check_empty() == 1)
                continue;
            PhoneBook.contact_count++;
            PhoneBook.index++;
        }
        if (command == "SEARCH")
        {
            PhoneBook.search_contact();
        }
    }
}
