#include "Span.hpp"


Span::Span(): _size(0){}

Span::Span(int i):  _size(i) {}

Span::Span(const Span& S)
{
    *this = S;
}

Span& Span::operator=(const Span& S)
{
    if (this == &S)
        return *this;
    _size = S._size;
    array = S.array;
    return *this;
}

void Span::addNumber(int num)
{
    if ((int)array.size() == _size)
        throw std::out_of_range("index out of range");
    array.push_back(num);
    return ;
}

int Span::shortestSpan()
{
    if (array.size() <= 1)
        throw std::length_error("array smaller than 2");
    std::vector<int> copy(this->array);
    std::sort(copy.begin(), copy.end());
    int min_span = copy[1] - copy[0];
    for (std::vector<int>::iterator it = copy.begin(); it != copy.end() - 1; it++)
    {
        if (*(it+1) - *it < min_span)
            min_span = *(it+1) - *it;
    }
    return min_span;

}
int Span::longestSpan()
{
    if (array.size() <= 1)
        throw std::length_error("array smaller than 2");
    return *std::max_element(array.begin(), array.end()) - *std::min_element(array.begin(), array.end());
}

Span::~Span(){}