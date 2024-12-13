#include "Convert.hpp"
#include <ctime>

int main (int argc, char **argv)
{
    if (argc != 2 && std::cout << "wrong input" << std::endl)
        return 1;
    ScalarConverter::convert(argv[1]);
}