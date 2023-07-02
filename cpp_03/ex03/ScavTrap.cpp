/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:48:05 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/01 20:14:33 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	this->setName("ScavTrap");
	this->setInitialValues();
}
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap Named Constructor called" << std::endl;
	this->setInitialValues();
}
ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap()
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	*this = src; 
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::setInitialValues(void)
{
	this->setClassName("ScavTrap");
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

void ScavTrap::attack(std::string const & target)
{
	if (ClapTrap::NoMorePoints())
		return ;
	std::cout << RED << this->getNameAndClassName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << RESET << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate( void )
{
	std::cout << this->getNameAndClassName() << " is on Gate keeper mode" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap Copy Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setClassName(rhs.getClassName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return *this;
}
