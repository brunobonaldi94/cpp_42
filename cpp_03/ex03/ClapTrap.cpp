/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:48:05 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/02 12:04:20 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("ClapTrap")
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
	this->setInitialValues("ClapTrap", 10, 10, 0);
}
ClapTrap::ClapTrap(std::string name): _name(name)
{
	std::cout << "ClapTrap Named Constructor called" << std::endl;
	this->setInitialValues("ClapTrap", 10, 10, 0);
}
ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = src;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

void ClapTrap::setInitialValues(std::string className, int hitPoints, int energyPoints, int attackDamage)
{
	this->setClassName(className);
	this->setHitPoints(hitPoints);
	this->setEnergyPoints(energyPoints);
	this->setAttackDamage(attackDamage);
}

std::string ClapTrap::getNameAndClassName( void ) const
{
	return this->getClassName() + " " + this->getName();
}

bool ClapTrap::NoMorePoints(void) const
{
	if (this->getHitPoints() == 0)
	{
		std::cout << this->getNameAndClassName() << " has no more hit points" << std::endl;
		return (true);
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getNameAndClassName() << " has no more energy points" << std::endl;
		return (true);
	}
	return (false);
}

void ClapTrap::attack(std::string const & target)
{
	if (NoMorePoints())
		return ;
	std::cout << RED << this->getNameAndClassName() << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (NoMorePoints())
		return ;
	if (amount >= static_cast<unsigned int>(this->getHitPoints()))
	{
		this->setHitPoints(0);
		std::cout << YELLOW << this->getNameAndClassName() << " took " << amount << " of damage" << " and died" << RESET << std::endl;
		return ;
	}
	this->setHitPoints(this->getHitPoints() - amount);
	std::cout << YELLOW << this->getNameAndClassName() << " took " << amount << " of damage" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (NoMorePoints())
		return ;
	std::string point = amount > 1 ? " points" : " point";
	std::cout << BLUE << this->getNameAndClassName() << " repaired " << amount << point << RESET << std::endl;
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

void ClapTrap::setClassName(std::string className)
{
	this->_className = className;
}

std::string ClapTrap::getClassName( void ) const
{
	return this->_className;
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
	std::cout << "ClapTrap Copy Assignment operator called" << std::endl;
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

std::ostream & operator<<(std::ostream & o, ClapTrap const & src)
{
	o 	<< BLUE << src.getNameAndClassName() << std::endl 
		<< "Hit Points: " << src.getHitPoints() <<  std::endl 
		<< "Energy Points " << src.getEnergyPoints() << std::endl
		<< "Attack Damage " << src.getAttackDamage() << RESET<< std:: endl;
	return o;
}
