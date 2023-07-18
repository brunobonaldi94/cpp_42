/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatData.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:06:46 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/17 21:49:38 by bbonaldi         ###   ########.fr       */
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


bool FloatData::checkLimits(double paramConverted)
{
	bool conversionSucceed = AData<float, double>::checkConversion(paramConverted);
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
	std::string param = this->prepareFloatingPointParam();

	if (this->_isPseudoLiteral)
		return static_cast<float>(this->_resultOverUnderFlow);

	double paramDouble = this->handleOverUnderFlow(param);

	return static_cast<float>(paramDouble);
}

bool FloatData::dealPseudoLiterals()
{
	if (!this->_isPseudoLiteral)
		return false;
	
	std::string plusOrMinusSign = "";
	if (this->_param[0] == '-' || this->_param[0] == '+')
		plusOrMinusSign = this->_param[0];
	std::cout << GREEN << "float: " << plusOrMinusSign << this->_result << "f" << RESET << std::endl;
	return true;
}

bool FloatData::dealFloatingPoint()
{
	size_t pos = this->_param.find(".");
	bool isFloatingPoint = pos != std::string::npos;
	if (!isFloatingPoint)
		return false;
	this->_param = this->eraseCharFromParam(this->_param, 'f');
	std::string decimalPlace = this->_param.substr(pos + 1);
	bool isAllZero = this->count_chars(decimalPlace, '0') == decimalPlace.length();
	std::string decimalPlaceAdder = isAllZero ? ("." + decimalPlace ) : "";
	std::cout << GREEN << "float: " << this->_result << decimalPlaceAdder << "f"  << RESET << std::endl;
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
		std::cout << GREEN << "float: " << this->_result << floatAdder << RESET << std::endl;
	}
	catch(FloatData::BadCast &e)
	{
		std::cout << RED << "float: " << e.getResult() << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
