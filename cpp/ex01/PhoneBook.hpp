#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include "Contact.hpp"
# define string std::string

class PhoneBook
{
	public:
		int contact_count;
		int index;
		Contact Contacts[8];
		PhoneBook();
		void search_contact();
		void print_contact(int x);
};

void print_details(string str);

#endif