/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:28:21 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/15 22:39:38 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->setType("WrongCat");
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal()
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = src;
}

WrongCat & WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
		this->setType(rhs.getType());
	return *this;
}

void WrongCat::makeSound ( void ) const
{
	std::cout << GREEN << "Meow 🐈" << RESET << std::endl;
}
