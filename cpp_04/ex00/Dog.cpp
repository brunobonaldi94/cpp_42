/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:28:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/06 19:48:43 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->setType("Dog");
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(Dog const &src) : Animal()
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = src;
}

Dog & Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog Copy assignment Operator called" << std::endl;
	if (this != &rhs)
		this->setType(rhs.getType());
	return *this;
}

void Dog::makeSound ( void ) const
{
	std::cout << GREEN << "Bark 🐶" << RESET << std::endl;
}
