#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
#include "PhoneBook.hpp"
# define string std::string

class Contact
{
  public:
	string 	first_name;
	string 	last_name;
	string 	nickname;
	string 	phone_number;
	string	darkest_secret;
	Contact();
	void add_contact();
	int check_empty();
};

#endif
