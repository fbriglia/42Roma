#include <iostream>
#include <stdio.h>

int main()
{
    std::string bello = "HI THIS IS BRAIN";
    std::string &ref = bello;
    std::string *ptr = &bello;

    std::cout << "string address = " <<  &bello << std::endl;
    std::cout << "ref address = " <<  &ref << std::endl;
    std::cout << "tpr address = " <<  &ptr << std::endl;
    std::cout << "string value = " <<  bello << std::endl;
    std::cout << "ref value = " <<  ref << std::endl;
    std::cout << "ptr value = " <<  ptr << std::endl;
}