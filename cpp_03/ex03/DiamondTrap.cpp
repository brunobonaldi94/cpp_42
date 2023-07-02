/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:28:54 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/01 22:55:21 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	ClapTrap::setClassName("DiamondTrap");
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap Named Constructor called" << std::endl;
	ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	ClapTrap::setClassName("DiamondTrap");
	ClapTrap::setName(name + "_clap_name");
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}
DiamondTrap::DiamondTrap(DiamondTrap const & src): ClapTrap(), ScavTrap(), FragTrap()
{
		std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = src;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	std::cout << "DiamondTrap Copy Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->setClassName(rhs.getClassName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return *this;
}
std::string DiamondTrap::getNameAndClassName( void ) const
{
	return this->getClassName() + " " + this->getName();
}

std::string DiamondTrap::getName( void ) const
{
	return this->_name;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
