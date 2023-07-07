/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:16:51 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/06 19:54:08 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("AAnimal")
{
	std::cout << "AAnimal Default Constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "AAnimal Copy Constructor called" << std::endl;
	*this = src;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "AAnimal Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
		this->setType(rhs.getType());
	return *this;
}

void AAnimal::makeSound(void)const
{
	std::cout << "AAnimal Sound" << std::endl;
}
std::string AAnimal::getType(void) const
{
	return this->_type;
}

void AAnimal::setType(std::string type)
{
	this->_type = type;
}
