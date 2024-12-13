#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Brain Constructor Called" << std::endl;
}
Brain::Brain(const Brain& B) 
{
    std::cout << "Brain Copy Constructor Called" << std::endl;
    *this = B;
}
Brain& Brain::operator=(const Brain& B)
{
    std::cout << "Brain override = called" << std::endl;
    if (this != &B)
    {
        for(int i = 0; i < 100; i++)
            ideas[i] = B.ideas[i];
    }
    return (*this);    
}

Brain::~Brain()
{
    std::cout << "Brain Deconstructor Called" << std::endl;
}