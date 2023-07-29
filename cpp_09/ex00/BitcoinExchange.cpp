/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:27:13 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/28 23:53:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename): _filename(filename), _fileInput(NULL), _fileData(NULL)
{
	debug("BitcoinExchange constructor called", YELLOW);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	debug("BitcoinExchange copy constructor called", YELLOW);
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{
	debug("BitcoinExchange destructor called", YELLOW);
	if (this->_fileInput)
		delete this->_fileInput;
	if (this->_fileData)
		delete this->_fileData;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	debug("BitcoinExchange assignation operator called", YELLOW);
	if (this != &rhs)
		this->_filename = rhs._filename;
	return (*this);
}


// Validate Date and Price

std::list<std::string> BitcoinExchange::split(std::string str, char delimiter)
{
	std::stringstream ss(str);
	std::string currentString;
	std::list<std::string> strSplit;
	while(std::getline(ss, currentString, delimiter))
		strSplit.push_back(currentString);
	return strSplit;
}

std::string BitcoinExchange::trim(std::string str)
{
	std::string::iterator it = str.begin();
	while (it != str.end() && std::isspace(*it))
		it++;
	std::string::iterator it2 = str.end();
	do
	{
		it2--;
	} while (std::distance(it, it2) > 0 && std::isspace(*it2));
	return std::string(it, it2 + 1);
}

bool BitcoinExchange::CheckDatePart(std::string datePart, size_t len, int min, int max)
{
	return datePart.size() == len && std::atoi(datePart.c_str()) >= min && std::atoi(datePart.c_str()) <= max;
}

bool BitcoinExchange::IsValidDate(std::string date)
{
	try 
	{
		std::list<std::string> dateList = this->split(date, '-');
		if (dateList.size() != 3)
			throw BitcoinExchange::BadDateException(date);
		
		std::list<std::string>::iterator it = dateList.begin();

		bool isValidYear = this->CheckDatePart(*it, 4, 2009, 2022);
		bool isValidMonth = this->CheckDatePart(*(++it), 2, 1, 12);
		bool isValidDay = this->CheckDatePart(*(++it), 2, 1, 31);
		if (!isValidYear || !isValidMonth || !isValidDay)
			throw BitcoinExchange::BadDateException(date);
		return (isValidYear && isValidMonth && isValidDay);
	}
	catch (BitcoinExchange::BadDateException &e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
}

bool BitcoinExchange::IsValidPrice(std::string price, size_t max)
{
	try 
	{
		char *endPtr;

		long double priceNumber = std::strtold(price.c_str(), &endPtr);
		if (endPtr[0] != '\0')
			throw BitcoinExchange::BadPriceException("Error: not a number.");
		if (priceNumber < 0)
			throw BitcoinExchange::BadPriceException("Error: not a positive number.");
		if (priceNumber > max)
			throw BitcoinExchange::BadPriceException("Error: too large number.");
		return true;
	}
	catch (BitcoinExchange::BadPriceException &e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
}

// File Handling

void BitcoinExchange::openFile(std::string filename)
{
	this->_fileInput = new std::ifstream();
	this->_fileInput->open(filename.c_str());
	if (!this->_fileInput->is_open())
		throw BitcoinExchange::FileErrorException("Error: could not open file.");
}

std::string BitcoinExchange::ReadLineInputFile(bool & isEOF)
{
	try
	{	
		std::string line;

		if (!this->_fileInput)
			this->openFile(this->_filename);
		if (!std::getline(*this->_fileInput, line))
			isEOF = true;
		return line;
	}
	catch (BitcoinExchange::FileErrorException &e)
	{
		std::cerr << e.what() << std::endl;
		return "";
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return "";
	}
}

void BitcoinExchange::getDataFromFile(void)
{
	std::string line;
	size_t line_number = 0;
	this->_fileData = new std::ifstream();
	this->_fileData->open("data.csv");

	if (!this->_fileData->is_open())
		throw BitcoinExchange::FileErrorException("Error: could not open file.");
	while (std::getline(*this->_fileData, line))
	{
		if (line_number == 0)
		{
			line_number++;
			continue;
		}
		std::list<std::string> data = this->split(line, ',');
		if (data.size() != 2)
			throw BitcoinExchange::FileErrorException("Error: bad data file.");
		std::string date = this->trim(data.front());
		std::string exchangeRate = this->trim(data.back());
		if (!this->IsValidDate(date) || !this->IsValidPrice(exchangeRate, INT_MAX))
			throw BitcoinExchange::FileErrorException("Error: bad data file.");
		this->_data[date] = std::atof(exchangeRate.c_str());
	}
}

// Do Exchange Rate Calculation

bool CompareKeys::operator()(const std::pair<const std::string, float>& lhs, const std::string& rhs) const
{
	return lhs.first < rhs;
}

float BitcoinExchange::getExchangeRate(std::string date)
{
	try 
	{
		std::map<std::string, float>::iterator it = this->_data.find(date);
		if (it == this->_data.end())
		{
			CompareKeys compare;
			it = std::lower_bound(this->_data.begin(), this->_data.end(), date, compare);
			if (it == this->_data.end())
				throw BitcoinExchange::FileErrorException("Error: bad data file.");
			if (it == this->_data.begin() && it->first != date)
				throw BitcoinExchange::FileErrorException("The lowest date is " + this->_data.begin()->first + " and date provided was: " + date);
			--it;
			return it->second;
		}
		
		return it->second;
	}
	catch (BitcoinExchange::FileErrorException &e)
	{
		std::cerr << e.what() << std::endl;
		return -1;
	}
}

void BitcoinExchange::DoExchangeEachLine(std::string line)
{
	try
	{
		std::list<std::string> data = this->split(line, '|');
		if (data.size() != 2)
			throw BitcoinExchange::FileErrorException("Error: bad file input => " + line);
		std::string date = this->trim(data.front());
		std::string price = this->trim(data.back());
		if (!this->IsValidDate(date) || !this->IsValidPrice(price, 1000))
				return ;
		float exchangeRate = this->getExchangeRate(date);
		if (exchangeRate == -1)
			return ;
		std::cout << date << " => " << exchangeRate * std::atof(price.c_str()) << std::endl;
	}
	catch (BitcoinExchange::FileErrorException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void BitcoinExchange::DoExchange(void)
{
	try
	{	
		std::string line;
		bool isEOF = false;
		size_t line_number = 0;

		this->getDataFromFile();
		this->openFile(this->_filename);

		while (true)
		{
			line = this->ReadLineInputFile(isEOF);
			if (isEOF)
				break;
			if (line_number == 0)
			{
				line_number++;
				continue;
			}
			this->DoExchangeEachLine(line);
		}
	}		
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// Exceptions

BitcoinExchange::BadDateException::BadDateException(std::string date): _errorMessage("Error: bad input => " + date)
{
	debug("BadDateException constructor called", YELLOW);
}

BitcoinExchange::BadDateException::~BadDateException(void) throw()
{
	debug("BadDateException destructor called", YELLOW);
}

const char* BitcoinExchange::BadDateException::what() const throw()
{
	return (_errorMessage.c_str());
}

BitcoinExchange::BadPriceException::BadPriceException(std::string errorMessage): _errorMessage(errorMessage)
{
	debug("BadPriceException constructor called", YELLOW);
}

BitcoinExchange::BadPriceException::~BadPriceException(void) throw()
{
	debug("BadPriceException destructor called", YELLOW);
}

const char* BitcoinExchange::BadPriceException::what() const throw()
{
	return (_errorMessage.c_str());
}

BitcoinExchange::FileErrorException::FileErrorException(std::string errorMessage): _errorMessage(errorMessage)
{
	debug("BadPriceException constructor called", YELLOW);
}

BitcoinExchange::FileErrorException::~FileErrorException(void) throw()
{
	debug("BadPriceException destructor called", YELLOW);
}

const char* BitcoinExchange::FileErrorException::what() const throw()
{
	return (_errorMessage.c_str());
}
