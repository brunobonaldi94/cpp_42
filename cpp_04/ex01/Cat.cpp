/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:28:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/20 21:49:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->setType("Cat");
	this->brain = new Brain();
	std::cout << "Cat Default constructor called" << std::endl;

}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat(Cat const &src) : Animal()
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

Cat & Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
	{
		this->setType(rhs.getType());
		this->brain->setIdeas(rhs.getBrain()->getIdeas());
	}
	return *this;
}

void Cat::makeSound ( void ) const
{
	std::cout << "Meow" << std::endl;
}

Brain * Cat::getBrain( void ) const
{
	return this->brain;
}

void Cat::setBrain(Brain *brain)
{
	this->brain = brain;
}
