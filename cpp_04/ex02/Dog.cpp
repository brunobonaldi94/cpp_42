/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:28:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/20 21:48:59 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
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

Dog::Dog(Dog const &src) : AAnimal()
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
	std::cout << "Bark" << std::endl;
}


Brain * Dog::getBrain( void ) const
{
	return this->brain;
}

void Dog::setBrain(Brain *brain)
{
	this->brain = brain;
}
