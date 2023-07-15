/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharData.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:51:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 12:22:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CharData.hpp"

CharData::CharData() : AData<char, int>()
{
	debug("CharData default constructor called", GREEN);
}

CharData::CharData(std::string param) : AData<char, int>(param)
{
	debug("CharData parametric constructor called", GREEN);
}

CharData::~CharData()
{
	debug("CharData destructor called", RED);
}

CharData::CharData(CharData const &src): AData<char, int>(src._param)
{
	debug("CharData copy constructor called", GREEN);
	*this = src;
}

CharData & CharData::operator=(CharData const &rhs)
{
	debug("CharData assignation operator called", GREEN);
	if (this != &rhs)
		this->_param = rhs._param;
	return (*this);
}

int CharData::handleResultOverUnderFlow(std::string param)
{
	this->_resultOverUnderFlow = std::atoi(param.c_str());
	return (this->_resultOverUnderFlow);
}

bool CharData::checkLimits()
{
	bool conversionSucceed = AData<char, int>::checkConversion(this->_resultOverUnderFlow);
	return (conversionSucceed);
}

char CharData::tryToConvert()
{
	std::string param = this->_param;

	int countOfDots = this->count_chars(param, '.');
	if (countOfDots > 1 || this->getPseudoLiterals(param).length() > 0)
		throw CharData::BadCast("impossible");
	if (countOfDots == 1)
		param = param.substr(0, param.find("."));
	
	param = this->eraseParamFromChar(param, 'f');

	bool isAllDigit = this->isAll(std::isdigit, param);
	if (!isAllDigit)
		throw CharData::BadCast("impossible");

	int paramInt = this->handleResultOverUnderFlow(param);
	if (!this->checkLimits())
		throw CharData::BadCast("impossible");
	bool isPrintable = std::isprint(paramInt);
	if (!isAllDigit)
		throw CharData::BadCast("impossible");
	else if (isAllDigit && !isPrintable)
		throw CharData::BadCast("Non displayable");
	return static_cast<char>(paramInt);
}

void CharData::printConverted()
{
	try
	{
		this->_result = this->tryToConvert();
		std::cout << "char: " << this->_result << std::endl;
	}
	catch(CharData::BadCast &e)
	{
		std::cout << "char: " << e.getResult() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
