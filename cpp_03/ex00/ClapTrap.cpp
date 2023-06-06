/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:48:05 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/05 22:35:45 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() { }
ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->getName() << " has been created" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &src)
{ 
	*this = src; 
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->getName() << " has been destroyed" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	if (this->getHitPoints() == 0 || this->getEnergyPoints() == 0)
		return ;
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() == 0 || this->getEnergyPoints() == 0)
		return ;
	if (amount >= this->getHitPoints())
	{
		this->setHitPoints(0);
		std::cout << "ClapTrap" << this->getName() << " has died" << std::endl;
		return ;
	}
	this->setHitPoints(this->getHitPoints() - amount);
	std::cout << "ClapTrap" << this->getName() << " took " << amount << " of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() == 0 || this->getEnergyPoints() == 0)
		return ;
	std::string point = amount > 1 ? " points" : " point";
	std::cout << "ClapTrap" << this->getName() << " repaired " << amount << point << std::endl;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

std::string ClapTrap::getName( void ) const
{
	return this->_name;
}
void ClapTrap::setHitPoints(int const hitPoints)
{
	this->_hitPoints = hitPoints;
}
int ClapTrap::getHitPoints( void ) const
{
	return this->_hitPoints;
}
void ClapTrap::setEnergyPoints(int const energyPoints)
{
	this->_energyPoints = energyPoints;
}
int ClapTrap::getEnergyPoints( void ) const
{
	return this->_energyPoints;
}
void ClapTrap::setAttackDamage(int const attackDamage)
{
	this->_attackDamage = attackDamage;
}
int ClapTrap::getAttackDamage( void ) const
{
	return this->_attackDamage;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setHitPoints(rhs.getHitPoints());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return *this;
}
