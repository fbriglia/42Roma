#include "Convert.hpp"
#include <cstdlib>
#include <string>

__type__ ScalarConverter::type = DEF;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& SC)
{
    *this = SC;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& SC)
{
    type = SC.type;
    return *this;
}

int ScalarConverter::parse(const std::string& literal)
{
    int i = 0;
    type = INT;
    if (!(literal[0] >= '0' && literal[0] <= '9') && !literal[1])
    {
            type = CHAR;
            return 0;
    }
    for (; literal[i] && type != CHAR; i++)
    {
        char c = literal[i];
        if (!(c >= '0' && c <= '9' ) && c != '.' && c != 'f' && c != '-')
            return 1;
        else if (c == '.' )
        {
            if (!literal[i+1] || literal[i+1] == 'f')
                return 1; 
            else if (type == DOUBLE)
                return 1;
            type = DOUBLE;
        }    
    }
    if (literal[i-1] == 'f' )
    {
        if(type != DOUBLE)
            return 1;
        type = FLOAT;
    }
    return 0;

}

void    ScalarConverter::print(std::string& literal)
{
    if (type == CHAR)
    {
        if (literal[0] >= 32)
            std::cout << "char: '" << literal[0] << "'"<<std::endl;
        else
            std::cout << "char: " << "non printable" << std::endl;
        std::cout << "int: " << (int)literal[0] << std::endl;
        std::cout << "double: "<< (double)literal[0] << ".0" << std::endl;
        std::cout << "float: "<< (float)literal[0] << ".0f" << std::endl;
    }

    else if (type == INT)
    {
        if (atoi(literal.c_str()) >= 32)
            std::cout << "char: '" << ((char)atoi(literal.c_str())) << "'" << std::endl;
        else
            std::cout << "char: " << "non printable" << std::endl;
        std::cout << "int: " << atoi(literal.c_str()) << std::endl;
        std::cout << "double: "<< atoi(literal.c_str()) << ".0" << std::endl;
        std::cout << "float: "<< atoi(literal.c_str()) << ".0f" << std::endl;
    }

    else if (type == DOUBLE)
    {
        if (atoi(literal.c_str()) >= 32)
            std::cout << "char: '" << ((char)atoi(literal.c_str())) << "'" << std::endl;
        else
            std::cout << "char: " << "non printable" << std::endl;
        std::cout << "int: " << atoi(literal.c_str()) << std::endl;
        if (literal[0] == '.')
            literal.insert(0, "0");
        std::cout << "double: "<< literal << std::endl;
        std::cout << "float: "<< atof(literal.c_str()) << "f"<< std::endl;
    }

    else if (type == FLOAT)
    {
        if (atoi(literal.c_str()) >= 32)
            std::cout << "char: '" << ((char)atoi(literal.c_str())) << "'" << std::endl;
        else
            std::cout << "char: " << "non printable" << std::endl;
        std::cout << "int: " << atoi(literal.c_str()) << std::endl;
        literal.erase(literal.length()-1) ;
        if (literal[0] == '.')
            literal.insert(0, "0");
        std::cout << "double: "<< literal << std::endl;
        std::cout << "float: "<< literal << "f"<< std::endl;
    }

}

void ScalarConverter::print_special(std::string & literal)
{
    if (literal == "nan")
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : nanf" << std::endl;
        std::cout << "double : nan" << std::endl;
    }

    
}

void ScalarConverter::convert(std::string literal)
{
    int x = 0;
    if (literal != "nan" && literal != "inf" && literal != "-inf")
        x = parse(literal);
    if (!x)
        print_special(literal);
    if (1 == x)
    {
        std::cout << "ERROR" << std::endl;
        return ;
    }
    print(literal);

}
ScalarConverter::~ScalarConverter(){}