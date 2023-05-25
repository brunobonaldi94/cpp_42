/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:08:26 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 21:43:36 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() { }
HumanB::HumanB( std::string name ): name(name), weapon(NULL) { }
HumanB::~HumanB() { }

std::string HumanB::getName(void) const 
{
	return this->name;
}

void HumanB::setName( std::string const name )
{
	this->name = name;
}

Weapon *HumanB::getWeapon( void ) const 
{
	return (this->weapon);
}
void HumanB::setWeapon( Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack( void )
{
	std::string	weaponType = this->getWeapon() ? this->getWeapon()->getType() : "";
	std::cout << this->getName() << " attacks with their " << weaponType << std::endl;
}
