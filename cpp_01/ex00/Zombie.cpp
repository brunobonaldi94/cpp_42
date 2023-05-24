/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:47:15 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/23 22:28:40 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() { }
Zombie::Zombie(std::string name): name(name) { }
Zombie::~Zombie()
{
	std::cout << this->getName() << ": I am dyinggggggg!" << std::endl;
}

std::string	Zombie::getName( void ) const
{
	return (this->name);
}

void	Zombie::announce( void )
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

