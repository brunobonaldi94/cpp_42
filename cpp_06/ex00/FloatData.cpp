/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatData.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:06:46 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 12:09:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FloatData.hpp"

FloatData::FloatData()
{
	debug("FloatData default constructor called", GREEN);
}

FloatData::FloatData(std::string param) : AData<float, double>(param)
{
	debug("FloatData parametric constructor called", GREEN);
}

FloatData::~FloatData()
{
	debug("FloatData destructor called", RED);
}

FloatData::FloatData(FloatData const &src): AData<float, double>(src._param)
{
	debug("FloatData copy constructor called", GREEN);
	*this = src;
}

FloatData & FloatData::operator=(FloatData const &rhs)
{
	debug("FloatData assignation operator called", GREEN);
	if (this != &rhs)
		this->_param = rhs._param;
	return (*this);
}


bool FloatData::checkLimits()
{
	bool conversionSucceed = AData<float, double>::checkConversion(this->_resultOverUnderFlow);
	return (conversionSucceed);
}

double FloatData::handleResultOverUnderFlow(std::string param)
{
	char* endPtr;
	this->_resultOverUnderFlow = std::strtod(param.c_str(), &endPtr);
	if (endPtr[0] != '\0')
		throw FloatData::BadCast("impossible");
	return (this->_resultOverUnderFlow);
}

float FloatData::tryToConvert()
{
	std::string param = this->_param;

	int countOfDots = this->count_chars(param, '.');
	if (countOfDots > 1)
		throw FloatData::BadCast("impossible");

	if (this->getPseudoLiterals(param).length() > 0)
		return static_cast<float>(this->_resultOverUnderFlow);

	param = this->eraseParamFromChar(param, 'f');

	double paramDouble = this->handleResultOverUnderFlow(param);
	if (param.at(0) == '+' || param.at(0) == '-')
		param.erase(0, 1);
	bool isAllDigit = this->isAll(std::isdigit, this->eraseParamFromChar(param, '.'));
	if (!isAllDigit || !this->checkLimits())
		throw FloatData::BadCast("impossible");
	return static_cast<float>(paramDouble);
}

bool FloatData::dealPseudoLiterals()
{
	if (!this->_isPseudoLiteral)
		return false;
	
	if (this->_param == "nanf" || this->_param.find("inff") != std::string::npos)
		std::cout << "float: " << this->_param << std::endl;
	else
		std::cout << "float: " << this->_param  << "f" << std::endl;
	return true;
}

bool FloatData::dealFloatingPoint()
{
	size_t pos = this->_param.find(".");
	bool isFloatingPoint = pos != std::string::npos;
	if (!isFloatingPoint)
		return false;
	this->_param = this->eraseParamFromChar(this->_param, 'f');
	std::string decimalPlace = this->_param.substr(pos + 1);
	bool isAllZero = this->count_chars(decimalPlace, '0') == decimalPlace.length();
	std::string decimalPlaceAdder = isAllZero ? ("." + decimalPlace ) : "";
	std::cout << "double: " << this->_result << decimalPlaceAdder << "f" << std::endl;
	return true;		
}

void FloatData::printConverted()
{
	try
	{
		this->_result = this->tryToConvert();
	
		if (this->dealPseudoLiterals() || this->dealFloatingPoint())
			return ;
		std::string floatAdder = ".0f";
		std::cout << "float: " << this->_result << floatAdder << std::endl;
	}
	catch(FloatData::BadCast &e)
	{
		std::cout << "float: " << e.getResult() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
