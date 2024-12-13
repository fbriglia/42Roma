#include "RPN.hpp"
#include <cctype>
#include <deque>


bool checkInput(std::string input)
{
    int i = 0;
    while(input[i] == ' ')
        i++;
    for (; (int)input.length() > i; i++)
    {
        if (i % 2 == 1 && input[i] != ' ')
            return false;
        else if (i % 2 == 0 && input[i] != '/' && input[i] != '*' && input[i] != '+' && input[i] != '-' && !std::isdigit(input[i]))
            return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    Rpn R;
    if (argc != 2)
    {
        std::cout << "Wrong input passed as arguments" << std::endl;
        return 1;
    }
    if (!checkInput(argv[1]))
    {
        std::cout << "Wrong input format" << std::endl;
        return 1;
    }
    R.parseInput(argv[1]);
    R.algo();
    std::cout << R.dec[0].value << std::endl;
}