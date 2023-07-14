/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatData.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:06:46 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/14 17:11:11 by bbonaldi         ###   ########.fr       */
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
	std::string pseudoLiteral = this->getPseudoLiterals(param);
	if (pseudoLiteral.length() > 0)
		return static_cast<float>(this->_resultOverUnderFlow);

	if (param.at(param.length() - 1) == 'f')
		param.erase(param.length() - 1);

	double paramDouble = this->handleResultOverUnderFlow(param);
	if (param.at(0) == '+' || param.at(0) == '-')
		param.erase(0, 1);
	bool isAllDigit = this->isAll(std::isdigit, param.substr(0, param.find('.')));
	if (!isAllDigit || !this->checkLimits())
		throw FloatData::BadCast("impossible");
	return static_cast<float>(paramDouble);
}

void FloatData::printConverted()
{
	try
	{
		std::string floatAdder = "f";
		this->_result = this->tryToConvert();
	
		if (this->_isPseudoLiteral)
		{
			if (this->_param == "nanf" || this->_param.find("inff") != std::string::npos)
				std::cout << "float: " << this->_param << std::endl;
			else
				std::cout << "float: " << this->_param  << floatAdder << std::endl;
			return ;
		}

		if (this->_param.at(this->_param.length() - 1) == 'f' && !this->_isPseudoLiteral)
			this->_param.erase(this->_param.length() - 1);
		size_t pos = this->_param.find(".");
		if (pos == std::string::npos && !this->_isPseudoLiteral)
			floatAdder = ".0f";
		else if (pos !=  std::string::npos)
			floatAdder = this->_param.substr(pos, this->_param.length() - pos) + "f";
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
