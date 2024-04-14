#include "PhoneBook.hpp"

int main()
{
    PhoneBook   PhoneBook;
    string      command;
    int contact_count = 0;

    PhoneBook.index = 0;
    while(1)
    {
        if (contact_count == 8)
            contact_count = 0;
        std::cout << "Enter Command: " << std::ends;
        std::getline(std::cin, command);
        if (command == "EXIT")
        {
            std::cout << "PHONEBOOK CLOSING" << std::endl;
            return 0;
        }
        if (command == "ADD")
        {
            PhoneBook.Contacts[contact_count].add_contact();
            if (PhoneBook.Contacts[contact_count].check_empty() == 1)
                continue;
            contact_count++;
            PhoneBook.index++;
        }
        if (command == "SEARCH")
            PhoneBook.search_contact();
    }
}