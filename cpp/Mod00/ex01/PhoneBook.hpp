#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "./Contact.hpp"
# define string std::string

class PhoneBook
{
	public:
		int index;
		Contact Contacts[8];
		PhoneBook();
		void search_contact();
		void print_contact(int);
};

void print_details(string);

#endif