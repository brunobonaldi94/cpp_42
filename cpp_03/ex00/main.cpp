/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/05 22:42:01 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap cp0;
	ClapTrap cp("Jonny");
	ClapTrap cpclone(cp);
	ClapTrap cp1("Claudia");
	cp0 = cp1;


	return 0;
}
