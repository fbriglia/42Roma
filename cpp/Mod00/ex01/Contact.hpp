#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "iostream"
# define string std::string

class Contact
{
  public:
	Contact();
	void add_contact();
	int check_empty();
	string getfirst_name();
	string getlast_name();
	string getnickname();
	string getphone_number();
	string getdarkest_secret();

	private:
		string 	first_name;
		string 	last_name;
		string 	nickname;
		string 	phone_number;
		string	darkest_secret;
};

#endif
