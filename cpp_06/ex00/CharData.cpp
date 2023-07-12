/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharData.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:51:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/11 22:17:01 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CharData.hpp"

CharData::CharData() : AData<char>()
{
	std::cout << "CharData default constructor called" << std::endl;	
}

CharData::CharData(std::string param) : AData<char>(param)
{
	std::cout << "CharData parametric constructor called" << std::endl;	
}

CharData::~CharData()
{
	std::cout << "CharData destructor called" << std::endl;	
}

CharData::CharData(CharData const &src): AData<char>(src.getParam())
{
	std::cout << "CharData copy constructor called" << std::endl;	
	*this = src;
}

CharData & CharData::operator=(CharData const &rhs)
{
	std::cout << "CharData assignation operator called" << std::endl;	
	if (this != &rhs)
		this->setParam(rhs.getParam());
	return (*this);
}

char CharData::tryToConvert()
{
	std::string _param = this->getParam();

	int countOfDots = this->count_chars(_param, '.');
	if (countOfDots > 1)
		throw CharData::BadCast("impossible");
	if (countOfDots == 1)
		_param = _param.substr(0, _param.find("."));
	if (_param.at(_param.length() - 1) != 'f')
		_param.erase(_param.length() - 1);
	bool isAllDigit = this->isAll(std::isdigit, _param);
	if (!isAllDigit || _param.length() >= 4)
		throw CharData::BadCast("impossible");
	int _paramInt = std::atoi(_param.c_str());
	bool isPrintable = std::isprint(_paramInt);
	if ((isAllDigit || _param.length() == 1 ) && isPrintable)
		return static_cast<char>(_paramInt);
	else if (isAllDigit && !isPrintable)
		throw CharData::BadCast("Non displayable");
	throw CharData::BadCast("impossible");
}

void CharData::printConverted()
{
	try
	{
		char converted = this->tryToConvert();
		std::cout << "char: " << converted << std::endl;

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
