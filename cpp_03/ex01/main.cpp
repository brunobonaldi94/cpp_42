/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/01 22:28:45 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void attackAnother(ClapTrap &atacante, ClapTrap &defensor)
{
	atacante.attack(defensor.getName());
	defensor.takeDamage(atacante.getAttackDamage());
}

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void testConstructor()
{
	{
		std::cout << YELLOW << "Constructor Test" << RESET << std::endl;
		ScavTrap scav;
		std::cout << scav;
		ClapTrap clap;
		std::cout << clap;
		ScavTrap scav2("ScavTrapper");
		std::cout << scav2;
	}
	printSeparator();
}

void testCopyConstructorAndAssignmentOperator()
{
	{
		std::cout << YELLOW << "Testing Copy Constructor And Assignment Operator" <<  RESET << std::endl;
		ScavTrap scav(name);
		ScavTrap scav1(scav);
		ScavTrap scav2;
		scav2 = scav1;
		std::cout << scav;
		std::cout << scav1;
		std::cout << scav2;
	}
	printSeparator();
}

void testParentPublicFunctions()
{
	std::cout << YELLOW << "Test Public function in ClapTrap Class" << RESET << std::endl;
	{
		ClapTrap clap("Pai");
		ScavTrap scav("Filho");

		clap.setAttackDamage(1);
		clap.beRepaired(20);
		attackAnother(clap, scav);

		attackAnother(scav, clap);
		scav.beRepaired(100);
		scav.setAttackDamage(1000);
		std::cout << clap;
		std::cout << scav;
	}
	printSeparator();
}

void testChildPublicFunction()
{
	{
		std::cout << YELLOW << "Test Public function in ScavTrap Class" << RESET << std::endl;
		ScavTrap scav("ScavTrapper");
		scav.guardGate();
		scav.attack("Pai");
		std::cout << scav;
	}
	printSeparator();
}

int main( void )
{
	testConstructor();
	testCopyConstructorAndAssignmentOperator();
	testParentPublicFunctions();
	testChildPublicFunction();
	return 0;
}
