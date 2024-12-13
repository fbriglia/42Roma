#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "iostream"
#include <deque>
#include <stack>

template <typename T> class MutantStack: public std::stack<T>
{
    public:
        MutantStack() {}

        MutantStack(const MutantStack& other): std::stack<T>(other){}

        ~MutantStack()
        {
            this->c.clear();
        }

        MutantStack& operator=(const MutantStack& copy)
        {
            if (&copy == this)
                return *this;
            this->c = copy;
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() 
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};


#endif