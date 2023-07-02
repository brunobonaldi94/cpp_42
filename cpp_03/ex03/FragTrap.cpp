/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:48:05 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/02 12:03:39 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default Constructor called" << std::endl;
	this->setName("FragTrap");
	this->setInitialValues("FragTrap",100, 100, 30);
}
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap Named Constructor called" << std::endl;
	this->setInitialValues("FragTrap",100, 100, 30);
}
FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
	*this = src;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
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
