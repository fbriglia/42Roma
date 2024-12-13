#include "Base.hpp"

Base* Base::generate()
{
    if (time(0) % 3 == 0)
        return new A();
    else if (time(0) % 2 == 0)
        return new B();
    else 
        return new C();
}

std::string Base::getType(){
   return type;
}

std::string A::getType(){
   return classtype;
}

std::string B::getType(){
   return type;
}

std::string C::getType(){
   return type;
}

void Base::identify(Base* Base)
{
    std::cout << Base->getType() << std::endl;
}

void Base::identify(Base& Base)
{
    std::cout << Base.getType() << std::endl;
}
