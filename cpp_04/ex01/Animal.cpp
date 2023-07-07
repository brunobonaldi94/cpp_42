/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:16:51 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/06 20:03:47 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
		this->setType(rhs.getType());
	return *this;
}

void Animal::makeSound(void)const
{
	std::cout << GREEN << "Animal Sound 🅰️" << RESET << std::endl;
}
std::string Animal::getType(void) const
{
	return this->_type;
}

void Animal::setType(std::string type)
{
	this->_type = type;
}
