/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:28:54 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/10 16:38:22 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "Default Constructor DiamondTrap called" << std::endl;
	ClapTrap::setClassName("DiamondTrap");
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap has been created" << std::endl;
	ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	ClapTrap::setClassName("DiamondTrap");
	ClapTrap::setName(name + "_clap_name");
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap has been destroyed" << std::endl;
}
DiamondTrap::DiamondTrap(DiamondTrap const & src): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "Copy Constructor for DiamondTrap called" << std::endl;
	*this = src;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	std::cout << "Copy Assignment operator for DiamondTrap called" << std::endl;
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

/*
•Name, which is passed as parameter to a constructor
•ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
•Hit points (FragTrap)
•Energy points (ScavTrap)
•Attack damage (FragTrap)
•attack() (Scavtrap)
9


*/
