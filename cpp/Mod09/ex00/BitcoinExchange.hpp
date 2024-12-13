#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "iostream"
#include <fstream>
#include <list>

enum __error__ {
   OK, NEG, BADINPUT, INVALIDVALUE, DATETOOSMALL
};

struct raw 
{
    std::string _date;
    float _rate;
};

class BitcoinExchange {
    private:
        std::list<raw> _data;
        raw _input;
        void readCsv();
        void parseLine(std::string);
        bool parseInput();

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange& operator=(const BitcoinExchange&);
        int calculateAmount(std::string&);
        void printError(int error);
        bool isOk();
        ~BitcoinExchange(){}
};

#endif