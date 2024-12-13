#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    public:
        Animal();
        Animal(const Animal&);
        Animal& operator=(const Animal&);
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const = 0;
    protected:
        std::string type;
};


#endif