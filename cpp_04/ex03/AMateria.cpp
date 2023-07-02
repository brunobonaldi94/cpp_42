/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:39:16 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/02 12:36:45 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter & target)
{
	if (this->type == "ice")
		std::cout << BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
	if (this->type == "cure")
		std::cout << GREEN << "* heals " << target.getName() << "’s wounds *" << RESET << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}
