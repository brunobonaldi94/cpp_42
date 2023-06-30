/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:55:27 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/28 20:52:22 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	ramos = Zombie("ramos");
	ramos.announce();
	
	//created on Heap using new
	Zombie*	bruno = newZombie("bruno");
	bruno->announce();
	delete bruno;
	
	//created on stack
	randomChump("silva");

	return (0);
}
