#ifndef RPN_HPP
#define RPN_HPP

#include "iostream"
#include <stack>
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
        std::stack<node> dec;
        Rpn();
        ~Rpn();
        int three_num(int, int);
        void parseInput(std::string);
        void algo();
};

bool checkInput(std::string);


#endif