/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharData.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:51:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/17 20:29:39 by bbonaldi         ###   ########.fr       */
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

bool CharData::checkLimits(int paramConverted)
{
	bool conversionSucceed = AData<char, int>::checkConversion(paramConverted);
	return (conversionSucceed);
}

char CharData::tryToConvert()
{
	std::string param = this->prepareWholeIntParam();

	bool isAllAlpha = this->isAll(std::isalpha, this->removeSign(param));
	int paramInt = this->handleOverUnderFlow(param);
	if (isAllAlpha && param.length() == 1)
		paramInt = static_cast<int>(param[0]);
	bool isPrintable = std::isprint(paramInt);
	if (!isPrintable)
		throw CharData::BadCast("Non displayable");
	return static_cast<char>(paramInt);
}

void CharData::printConverted()
{
	try
	{
		this->_result = this->tryToConvert();
		std::cout << GREEN << "char: " << this->_result << RESET << std::endl;
	}
	catch(CharData::BadCast &e)
	{
		std::cout << RED << "char: " << e.getResult() << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
