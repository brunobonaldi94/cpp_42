/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:43:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 21:44:47 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
	 	Weapon club = Weapon("crude spiked club");
	 	HumanB jim("Jim");
	 	jim.setWeapon(club);
	 	jim.attack();
	 	club.setType("some other type of club");
	 	jim.attack();
	}
	return 0;
}
