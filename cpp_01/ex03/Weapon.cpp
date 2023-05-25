/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:59:09 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 21:49:26 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() { }
Weapon::~Weapon() { }
Weapon::Weapon( std::string const type ): type(type) { }

const std::string& Weapon::getType( void )
{	
	return (this->type);
}

void Weapon::setType( std::string const type )
{
	this->type = type;
};


