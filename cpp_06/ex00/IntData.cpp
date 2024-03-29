/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntData.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:51:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/12 17:05:02 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IntData.hpp"

IntData::IntData() : AData<int, long int>()
{
	debug("IntData default constructor called", BLUE);
}

IntData::IntData(std::string param) : AData<int, long int>(param)
{
	debug("IntData parametric constructor called", BLUE);
}

IntData::~IntData()
{	
	debug("IntData destructor called", BLUE);
}

IntData::IntData(IntData const &src): AData<int, long int>(src._param)
{
	debug("IntData copy constructor called", BLUE);
	*this = src;
}

IntData & IntData::operator=(IntData const &rhs)
{
	debug("IntData assignation operator called", BLUE);
	if (this != &rhs)
		this->_param = rhs._param;
	return (*this);
}

bool IntData::checkLimits(long int paramConverted)
{
	bool conversionSucceed = AData<int, long int>::checkConversion(paramConverted);
	return (conversionSucceed);
}

long int IntData::handleResultOverUnderFlow(std::string param)
{
	this->_resultOverUnderFlow = std::atol(param.c_str());
	return (this->_resultOverUnderFlow);
}

int IntData::tryToConvert()
{

	std::string param = this->prepareWholeIntParam();

	bool isAllDigit = this->isAll(std::isdigit, this->removeSign(param));
	if (!isAllDigit)
		throw IntData::BadCast("impossible");

	long int paramLongInt = this->handleOverUnderFlow(param);
	
	return static_cast<int>(paramLongInt);
}

void IntData::printConverted()
{
	try
	{
		this->_result = this->tryToConvert();
		std::cout << GREEN << "int: " << this->_result << RESET << std::endl;

	}
	catch(IntData::BadCast &e)
	{
		std::cout << RED << "int: " << e.getResult() << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
