/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:08:19 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 21:23:12 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon) { }
HumanA::~HumanA() { }

std::string HumanA::getName(void) const 
{
	return this->name;
}

void HumanA::setName( std::string const name )
{
	this->name = name;
}

Weapon HumanA::getWeapon( void )
{
	return this->weapon;
}
void HumanA::setWeapon( Weapon weapon)
{
	this->weapon = weapon;
}

void	HumanA::attack( void ) 
{
	std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}
