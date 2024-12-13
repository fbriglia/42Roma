#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
	readCsv();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& B)
{
	*this = B;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& B)
{
	if (&B == this)
		return *this;
	_data = B._data;
	_input = B._input;
	return *this;
}

void BitcoinExchange::printError(int err)
{
	switch(err)
	{
		case NEG:
			std::cout << "Error: not a positive number."<< std::endl;
			break;
		case BADINPUT:
			std::cout << "Error: bad input." << std::endl;
			break;
		case INVALIDVALUE:
			std::cout << "Error: invalid value." << std::endl;
			break;
		case DATETOOSMALL:
			std::cout << "Error: invalid date." << std::endl;
	}
}

void BitcoinExchange::parseLine(std::string line)
{
	raw r;

	r._date = line.substr(0, 10);
	r._rate = std::atof (line.substr(11).c_str());
	_data.push_back(r);
}

void	BitcoinExchange::readCsv()
{
	std::string		line;
	std::ifstream	_readcsv;

    _readcsv.open("data.csv");
    if(!_readcsv.is_open())
	{
        return;
	}
	std::getline(_readcsv,line);
	while(!line.empty())
	{
		std::getline(_readcsv, line);
		if (line.empty())
			return;
		parseLine(line);
	}
}

int BitcoinExchange::calculateAmount(std::string& line)
{
	if (line.length() < 13 || ('-' != line[4] || '-' != line[7] || line[10] != ' ' 
	|| line[11] != '|' || line[12] != ' '))
		return BADINPUT;
	if (line[13] == '-')
		return NEG;
	_input._date = line.substr(0, 10);
	if (_input._date < _data.begin()->_date)
		return DATETOOSMALL;
	for (int i = 0; i < (int)line.length(); i++)
	{
		if (i < 10 && _input._date[i] != '-' && (_input._date[i] < '0' || _input._date[i] > '9'))
			return BADINPUT;
		else if ( i > 12 && line[i] != '.' && (line[i] < '0' || line[i] > '9'))
			return BADINPUT;
	}		
	_input._rate = std::atof (line.substr(13).c_str());
	if (_input._rate < 0 || _input._rate > 1000)
		return INVALIDVALUE;
	std::list<raw>::iterator it = _data.begin();
	for (; it != _data.end() && it->_date < _input._date ; it++)
		continue;
	if (it->_date > _input._date)
		it--;
	std::cout << _input._date << " => " << 	_input._rate << " = "
	 << _input._rate * it->_rate << std::endl;
	return OK;
}

bool BitcoinExchange::isOk()
{
    return !_data.empty();
}
