/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:16:51 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/15 22:42:16 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
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
	std::cout << "Animal Sound" << std::endl;
}
std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::setType(std::string type)
{
	this->type = type;
}
