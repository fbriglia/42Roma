#ifndef BASE_HPP
#define BASE_HPP

#include "iostream"

class   Base {
    public:
        Base():type("Base"){}
        virtual ~Base(){}
        Base* generate();
        void identify(Base*);
        void identify(Base&);
        virtual std::string getType();
    private:
        std::string type;
};

class A : public Base
{
    public:
        A():classtype("A"){};
        std::string getType();
    private:
        std::string classtype;
};

class B: public Base
{
    public:
        B():type("B"){};
        std::string getType();
    private:
        std::string type;
};

class C: public Base
{
    public:
        C():type("C"){};
        std::string getType();
    private:
        std::string type;
};

#endif