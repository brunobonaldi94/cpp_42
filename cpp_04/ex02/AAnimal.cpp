/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:16:51 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/20 21:40:33 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal")
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
	return this->type;
}

void AAnimal::setType(std::string type)
{
	this->type = type;
}
