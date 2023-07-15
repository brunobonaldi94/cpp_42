/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleData.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:59:42 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 11:44:04 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoubleData.hpp"

DoubleData::DoubleData()
{
	debug("DoubleData default constructor called", GREEN);
}

DoubleData::DoubleData(std::string param) : AData<double, long double>(param)
{
	debug("DoubleData parametric constructor called", GREEN);
}

DoubleData::~DoubleData()
{
	debug("DoubleData destructor called", RED);
}

DoubleData::DoubleData(DoubleData const &src): AData<double, long double>(src._param)
{
	debug("DoubleData copy constructor called", GREEN);
	*this = src;
}

DoubleData & DoubleData::operator=(DoubleData const &rhs)
{
	debug("DoubleData assignation operator called", GREEN);
	if (this != &rhs)
		this->_param = rhs._param;
	return (*this);
}


bool DoubleData::checkLimits()
{
	bool conversionSucceed = AData<double, long double>::checkConversion(this->_resultOverUnderFlow);
	return (conversionSucceed);
}

long double DoubleData::handleResultOverUnderFlow(std::string param)
{
	char* endPtr;
	this->_resultOverUnderFlow = std::strtold(param.c_str(), &endPtr);
	if (endPtr[0] != '\0')
		throw DoubleData::BadCast("impossible");
	return (this->_resultOverUnderFlow);
}

double DoubleData::tryToConvert()
{
	std::string param = this->_param;

	int countOfDots = this->count_chars(param, '.');
	if (countOfDots > 1)
		throw DoubleData::BadCast("impossible");
	std::string pseudoLiteral = this->getPseudoLiterals(param);
	if (pseudoLiteral.length() > 0)
		return static_cast<double>(this->_resultOverUnderFlow);

	if (param.at(param.length() - 1) == 'f')
		param.erase(param.length() - 1);

	long double paramLongDouble = this->handleResultOverUnderFlow(param);
	if (param.at(0) == '+' || param.at(0) == '-')
		param.erase(0, 1);
	bool isAllDigit = this->isAll(std::isdigit, param.substr(0, param.find('.')));
	if (!isAllDigit || !this->checkLimits())
		throw DoubleData::BadCast("impossible");
	return static_cast<double>(paramLongDouble);
}

bool DoubleData::dealPseudoLiterals()
{
	if (!this->_isPseudoLiteral)
		return (false);
	if (this->_param == "nanf" || this->_param.find("inff") != std::string::npos)
		std::cout << "double: " << this->_param.erase(this->_param.length() -1) << std::endl;
	else
		std::cout << "double: " << this->_param  << std::endl;
	return true;
}

bool DoubleData::dealFloatingPoint()
{
	size_t pos = this->_param.find(".");
	bool isFloatingPoint = pos != std::string::npos;
	if (!isFloatingPoint)
		return false;
	this->_param = this->eraseParamFromChar(this->_param, 'f');
	std::string decimalPlace = this->_param.substr(pos + 1);
	bool isAllZero = this->count_chars(decimalPlace, '0') == decimalPlace.length();
	std::string decimalPlaceAdder = isAllZero ? ("." + decimalPlace ) : "";
	std::cout << "double: " << this->_result << decimalPlaceAdder << std::endl;
	return true;		
}

void DoubleData::printConverted()
{
	try
	{
		this->_result = this->tryToConvert();
			
		if (this->dealPseudoLiterals() || this->dealFloatingPoint())
			return ;

		std::string doubleAdder = ".0";
		std::cout << "double: " << this->_result << doubleAdder << std::endl;
	}
	catch(DoubleData::BadCast &e)
	{
		std::cout << "double: " << e.getResult() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
