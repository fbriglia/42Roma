#include "RPN.hpp"
#include <cctype>
#include <stack>
#include <vector>

Rpn::Rpn() {}

Rpn::~Rpn(){

}

int Rpn::three_num(int num_1, int num_2)
{
    int num_3 = dec.top().value;
    dec.pop();
    switch (dec.top().value) {
    case '+' : 
        num_2 = num_2 + num_3;
        break;
    case '-' : 
        num_2 = num_2 - num_3;
        break;
    case '/' : 
        num_2 = num_2 / num_3;
        break;
    case '*' : 
        num_2 = num_2 * num_3;
        break;
    }
    dec.pop();
    switch (dec.top().value) {
    case '+' : 
        num_2 = num_1 + num_2;
        break;
    case '-' : 
        num_2 = num_1 - num_2;
        break;
    case '/' : 
        num_2 = num_1 / num_2;
        break;
    case '*' : 
        num_2 = num_1 * num_2;
        break;
    }
    return num_2;

}

void    Rpn::algo()
{
    int num_1;
    int num_2;
    int result;
    num_1 = dec.top().value;
    dec.pop();
    num_2 = dec.top().value;
    dec.pop();
    switch (dec.top().value) {
        case '+' : 
            result = num_1 + num_2;
            break;
        case '-' : 
            result = num_1 - num_2;
            break;
        case '/' : 
            result = num_1 / num_2;
            break;
        case '*' : 
            result = num_1 * num_2;
            break;
        default:
            result = three_num(num_1, num_2);
            break;
    }
    dec.pop();
    node n_result = {INT, result};
    dec.push(n_result);
    if (dec.size() == 1)
        return ;
    algo();
}

void	Rpn::parseInput(std::string input)
{
    node node;
    if (input.length() > 0)
    {
        if (std::isdigit(input[input.length() - 1])) 
            node.type = INT;
        else
            node.type = OPERATOR;
        node.value = node.type ? input[input.length()-1] : input[input.length()-1] - 48;
        dec.push(node);
        if (input.length() == 1)
            return;
        parseInput(input.substr(0, input.length()-2));
    }
}
