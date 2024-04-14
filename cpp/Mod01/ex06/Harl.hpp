#ifndef HARL_HPP
# define HARL_HPP
#include <iostream>

class Harl
{
    private:
        void    debug();
        void    info();
        void    warning();
        void    error();
        struct  t_fn{
            std::string level;
            void (Harl::*fn)(void);
        };
    public:
        Harl();
        ~Harl();
        t_fn fn[4];
        void    complain(std::string);
};
#endif