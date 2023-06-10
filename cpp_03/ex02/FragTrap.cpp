/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:48:05 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/10 16:02:14 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Default Constructor FragTrap called" << std::endl;
	this->setName("FragTrap");
	this->setClassName("FragTrap");
}
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->setClassName("FragTrap");
	std::cout << "FragTrap has been created" << std::endl;
	ClapTrap::setHitPoints(100);
	ClapTrap::setEnergyPoints(100);
	ClapTrap::setAttackDamage(30);
}
FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "Copy Constructor for FragTrap called" << std::endl;
	*this = src;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap has been destroyed" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	if (ClapTrap::NoMorePoints())
		return ;
	std::cout << BLUE << this->getNameAndClassName() << " is sending a positive High Five for you 🖐" << RESET << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "Copy Assignment operator for FragTrap called" << std::endl;
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
