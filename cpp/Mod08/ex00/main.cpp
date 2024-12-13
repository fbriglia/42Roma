#include "easyfind.hpp"
#include <vector>

int main()
{
    int array[] = {34, 24, 79, 83};

    std::vector<int> v(array, array+4);
    std::vector<int>::iterator it = easyfind(v, 2);
    if (it != v.end())
        std::cout << "element found" << std::endl;
    else
        std::cout << "element not found" << std::endl;
    return 0;
}