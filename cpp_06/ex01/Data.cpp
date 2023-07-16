/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:12:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/16 18:47:04 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void): _value(0)
{
	debug("Data default constructor called", GREEN);
}

Data::Data(int value): _value(value)
{
	debug("Data parametric constructor called", GREEN);
}

Data::~Data(void)
{
	debug("Data destructor called", GREEN);
}

Data::Data(const Data &src)
{
	debug("Data copy constructor called", GREEN);
	*this = src;
}

Data &Data::operator=(const Data &rhs)
{
	debug("Data assignation operator called", GREEN);
	if (this != &rhs)
		this->_value = rhs._value;
	return (*this);
}

int Data::getValue(void) const
{
	return (this->_value);
}

std::ostream &operator<<(std::ostream &o, Data const &rhs)
{
	o << rhs.getValue();
	return (o);
}
