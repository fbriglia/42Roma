#include "BitcoinExchange.hpp"
#include <string>

int main(int argc, char *argv[])
{
    BitcoinExchange be;
    std::ifstream inputFile;
    std::string line;
    int err;

    if (argc != 2)
    {
        std::cerr << "Wrong number args" << std::endl;
        return 1;
    }
    
    if (!be.isOk())
    {
        std::cerr << "Error reading csv database" << std::endl;
        return 1;
    }
    
    inputFile.open(argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    std::getline(inputFile, line);
    while (inputFile)
    {
        std::getline(inputFile, line);
        if (line.empty())
            continue;
        err = be.calculateAmount(line);
        if (err)
            be.printError(err);
    }
    inputFile.close();

}