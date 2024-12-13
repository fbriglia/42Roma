#ifndef RPN_HPP
#define RPN_HPP

#include "iostream"
#include <deque>
#include <vector>
#include <list>

enum __type__ {
    INT , OPERATOR
};

struct node {
    int type;
    int value;
};

class Rpn {

    private:

    public:
        std::deque<node> dec;
        Rpn();
        ~Rpn();
        void parseInput(std::string);
        void algo();
};

bool checkInput(std::string);


#endif