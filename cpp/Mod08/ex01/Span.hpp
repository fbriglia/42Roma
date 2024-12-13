#ifndef SPAN_HPP
#define SPAN_HPP

#include "iostream"
#include "algorithm"
#include <stdexcept>
#include <vector>

class Span {

    private:
        std::vector<int> array;
        int _size;
        Span();

    public:
        Span(int);
        Span(const Span&);
        Span& operator=(const Span&);
        void addNumber(int);
        int shortestSpan();
        int longestSpan();
        ~Span();
};

#endif