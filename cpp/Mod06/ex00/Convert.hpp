#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>

enum __type__ {
    CHAR, INT, FLOAT, DOUBLE, DEF
};


class ScalarConverter {
    public:
        static int parse(const std::string&);
        static void print(std::string&);
        static void print_special(std::string&);
        static void convert(std::string);
        ~ScalarConverter();
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        static __type__ type;
};

#endif