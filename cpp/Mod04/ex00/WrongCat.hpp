#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat: public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const WrongCat&);
        WrongCat& operator=(const WrongCat&);
        ~WrongCat();
        std::string getType() const;
        void makeSound() const;
};


#endif