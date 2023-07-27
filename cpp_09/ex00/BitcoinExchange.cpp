/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:27:13 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/26 22:22:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename): _filename(filename), _file(NULL)
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
	if (this->_file)
	{
		this->_file->close();
		delete this->_file;
	}
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	debug("BitcoinExchange assignation operator called", YELLOW);
	if (this != &rhs)
		this->_filename = rhs._filename;
	return (*this);
}

bool BitcoinExchange::CheckDatePart(std::string datePart, size_t len, int min, int max)
{
	return datePart.size() == len && std::atoi(datePart.c_str()) >= min && std::atoi(datePart.c_str()) <= max;
}

bool BitcoinExchange::IsValidDate(std::string date)
{
	std::stringstream ss(date);
	std::string currentString;
	std::list<std::string> dateList;
	while(std::getline(ss, currentString, '-'))
		dateList.push_back(currentString);
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

bool BitcoinExchange::IsValidPrice(std::string price)
{
	long long priceNumber = std::atoll(price.c_str());
	if (priceNumber == 0 && price != "0")
		throw BitcoinExchange::BadPriceException("Error: not a number.");
	if (priceNumber < 0)
		throw BitcoinExchange::BadPriceException("Error: not a positive number.");
	if (priceNumber > 1000)
		throw BitcoinExchange::BadPriceException("Error: too large number.");
	return true;
}

void BitcoinExchange::openFile(std::string filename)
{
	this->_file = new std::ifstream();
	this->_file->open(filename.c_str());
	if (!this->_file->is_open())
		throw BitcoinExchange::FileErrorException("Error: could not open file.");
}

void BitcoinExchange::getDataFromFile(void)
{
	std::string line;
	size_t line_number = 0;
	std::ifstream file("./data.csv");
	if (!file.is_open())
		throw BitcoinExchange::FileErrorException("Error: could not open file.");
	while (std::getline(file, line))
	{
		if (line_number == 0)
		{
			line_number++;
			continue;
		}
		line_number++;

		std::stringstream ss(line);
		std::string currentString;
		std::list<std::string> dataList;
		while(std::getline(ss, currentString, ','))
			dataList.push_back(currentString);
		if (dataList.size() != 2)
			throw BitcoinExchange::FileErrorException("Error: bad data file.");
		if (this->IsValidDate(dataList.front()) && this->IsValidPrice(dataList.back()))
			this->_data[dataList.front()] = std::atoi(dataList.back().c_str());
	}
	file.close();
}

void BitcoinExchange::ReadInputFile(void)
{
	try
	{	
		std::string line;
		if (!this->_file)
			this->openFile(this->_filename);
		std::getline(*this->_file, line);
		std::cout << line << std::endl;
	}catch (BitcoinExchange::BadDateException &e)
	{
		std::cerr << e.what() << std::endl;
	} catch (BitcoinExchange::BadPriceException &e)
	{
		std::cerr << e.what() << std::endl;
	} catch (BitcoinExchange::FileErrorException &e)
	{
		std::cerr << e.what() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}


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
