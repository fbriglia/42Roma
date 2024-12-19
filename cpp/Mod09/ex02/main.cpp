#include "PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <deque>
#include <list>
#include <stack>
#include <string>
#include <utility>
#include <vector>

bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

int main(int argc, const char *argv[]) {
    if (argc <= 2) {
        std::cout << "PmergeMe: not enought args" << std::endl;
        return 1;
    }

    PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > > deq("std::deque");
    PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > > vec("std::vector");

    std::cout << "Before: ";
    for (int i = 1, nbr; i < argc; i++) {
        if (!is_number(argv[i])) {
            return 1;
        }
        nbr = std::atof(argv[i]);
        deq.push_back(nbr);
        vec.push_back(nbr);
        if (i < 8)
            std::cout << argv[i] << " ";
    }
    if (argc > 8)
        std::cout << "...";
    std::cout << std::endl;

    deq.sort();
    vec.sort();

    std::cout << "After: ";
    deq.printSorted();

    deq.printProcessTime();
    vec.printProcessTime();
    return 0;
}
