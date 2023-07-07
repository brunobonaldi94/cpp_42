/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:16:51 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/15 22:37:32 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "WrongAnimal Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
		this->setType(rhs.getType());
	return *this;
}

void WrongAnimal::makeSound(void)const
{
	std::cout << GREEN << "WrongAnimal Sound 🅰️" << RESET << std::endl;
}
std::string WrongAnimal::getType(void) const
{
	return this->_type;
}

void WrongAnimal::setType(std::string type)
{
	this->_type = type;
}
