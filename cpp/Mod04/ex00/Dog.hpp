#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog: public Animal {
    public:
        Dog();
        Dog(const Dog&);
        Dog& operator=(const Dog&);
        ~Dog();
        std::string getType() const;
        void makeSound() const;
};


#endif