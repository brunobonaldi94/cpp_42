/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:28:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/06 20:04:01 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->setType("Dog");
	this->brain = new Brain();
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->brain;
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
	{
		this->setType(rhs.getType());
		this->brain->setIdeas(rhs.getBrain()->getIdeas());
	}
	return *this;
}

void Dog::makeSound ( void ) const
{
	std::cout << GREEN << "Bark 🐶" << RESET << std::endl;
}


Brain * Dog::getBrain( void ) const
{
	return this->brain;
}

void Dog::setBrain(Brain *brain)
{
	this->brain = brain;
}
