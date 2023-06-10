/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:48:05 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/10 15:41:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "Default Constructor ScavTrap called" << std::endl;
	this->setName("ScavTrap");
	this->setClassName("ScavTrap");
}
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->setClassName("ScavTrap");
	std::cout << "ScavTrap has been created" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}
ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap()
{
	std::cout << "Copy Constructor for ScavTrap called" << std::endl;
	*this = src; 
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap has been destroyed" << std::endl;
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
	std::cout << "Copy Assignment operator for ScavTrap called" << std::endl;
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
