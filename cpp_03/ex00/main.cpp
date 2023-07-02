/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/01 22:28:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void attackAnother(ClapTrap &atacante, ClapTrap &defensor)
{
	atacante.attack(defensor.getName());
	defensor.takeDamage(atacante.getAttackDamage());
}

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void testDefaultConstructor()
{
	{
		std::cout << YELLOW << "DefaultConstructor" << RESET << std::endl;
		ClapTrap clap;
	}
	printSeparator();
}

void testNamedConstructor()
{
	{
		std::cout << YELLOW << "Testing Named Constructor" <<  RESET << std::endl;
		std::string name = "Clapper";
		ClapTrap clap(name);
	}
	printSeparator();
}

void testCopyConstructorAndAssignmentOperator()
{
	{
		std::cout << YELLOW << "Testing Copy Constructor And Assignment Operator" <<  RESET << std::endl;
		ClapTrap clap("Clapper");
		ClapTrap clap1(clap);
		ClapTrap clap3;
		clap3 = clap1;
	}
	printSeparator();
}

void testPublicFunction()
{
	{
		std::cout << YELLOW << "Testing Attack/Repair/TakeDamage function" <<  RESET << std::endl;
		ClapTrap atacante("Atacante");
		ClapTrap defensor("Defensor");
		atacante.setAttackDamage(1);
		defensor.beRepaired(10);
		while (!atacante.NoMorePoints())
			attackAnother(atacante, defensor);
		std::cout << atacante;
		std::cout << defensor;
	}
	printSeparator();
}

int main( void )
{
	testDefaultConstructor();
	testNamedConstructor();
	testCopyConstructorAndAssignmentOperator();
	testPublicFunction();
	return 0;
}
