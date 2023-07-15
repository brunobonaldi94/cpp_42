/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleData.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:59:42 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 16:50:31 by bbonaldi         ###   ########.fr       */
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


bool DoubleData::checkLimits(long double paramConverted)
{
	bool conversionSucceed = AData<double, long double>::checkConversion(paramConverted);
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
	std::string param = this->prepareFloatingPointParam();

	if (this->_isPseudoLiteral)
		return static_cast<double>(this->_resultOverUnderFlow);

	long double paramLongDouble = this->handleOverUnderFlow(param);

	return static_cast<double>(paramLongDouble);
}

bool DoubleData::dealPseudoLiterals()
{
	if (!this->_isPseudoLiteral)
		return (false);
	std::string plusOrMinusSign = "";
	if (this->_param[0] == '-' || this->_param[0] == '+')
		plusOrMinusSign = this->_param[0];
	std::cout << "double: " << plusOrMinusSign << this->_result << std::endl;
	return true;
}

bool DoubleData::dealFloatingPoint()
{
	size_t pos = this->_param.find(".");
	bool isFloatingPoint = pos != std::string::npos;
	if (!isFloatingPoint)
		return false;
	this->_param = this->eraseCharFromParam(this->_param, 'f');
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
		std::cout << GREEN;
		if (this->dealPseudoLiterals() || this->dealFloatingPoint())
			return ;

		std::string doubleAdder = ".0";
		std::cout << "double: " << this->_result << doubleAdder << std::endl;
		std::cout << RESET;
	}
	catch(DoubleData::BadCast &e)
	{
		std::cout << RED << "double: " << e.getResult() << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
