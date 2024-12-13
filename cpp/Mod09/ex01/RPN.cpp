#include "RPN.hpp"
#include <cctype>
#include <deque>
#include <vector>

Rpn::Rpn() {}

Rpn::~Rpn(){
    if (!dec.empty())
        dec.clear();
}


void    Rpn::algo()
{
    int result;
    std::deque<node>::iterator it = dec.begin();
    for (; it != dec.end() && it->type != OPERATOR; it++)
        continue;
    switch (it->value) {
        case '+' : 
            result = (it-2)->value + (it-1)->value;
            break;
        case '-' : 
            result = (it-2)->value - (it-1)->value;
            break;
        case '/' : 
            result = (it-2)->value / (it-1)->value;
            break;
        case '*' : 
            result = (it-2)->value * (it-1)->value;
            break;
    }
    (it-2)->value = result;
    dec.erase(it-1);
    dec.erase(it);
    if ((it-1) == dec.end())
        return ;
    algo();
}

void	Rpn::parseInput(std::string input)
{
    node node;
    if (int y = input.find(" ") != std::string::npos || input.length() == 1)
    {
        if (std::isdigit(input[0])) 
            node.type = INT;
        else
            node.type = OPERATOR;
        node.value = node.type ? input[0] : input[0] - 48;
        dec.push_back(node);
        if (input.length() == 1)
            return;
        parseInput(input.substr(y+1));
    }
}
