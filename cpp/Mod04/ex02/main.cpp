#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
const Animal* Animals[10];
for (int i = 0; i<5; i++)
    Animals[i] = new Dog();
for (int i = 5; i < 10; i++)
    Animals[i] = new Cat();
for (int i = 0; i < 10; i++)
{
    std::cout << Animals[i]->getType() << " " << std::endl;
    Animals[i]->makeSound();
}
for(int i = 0; i < 10; i++)
    delete Animals[i];
return 0;
}