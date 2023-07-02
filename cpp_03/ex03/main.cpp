/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/02 10:55:49 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


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
		FragTrap frag;
		std::cout << frag;
		DiamondTrap diam("DiamondTrapper");
		std::cout << diam;
		DiamondTrap diam2("DiamondTrapper2");
		std::cout << diam2;
	}
	printSeparator();
}

void testCopyConstructorAndAssignmentOperator()
{
	{
		std::cout << YELLOW << "Testing Copy Constructor And Assignment Operator" <<  RESET << std::endl;
		DiamondTrap diam("DiamondTrapper");
		DiamondTrap diam1(diam);
		DiamondTrap diam2;
		diam2 = diam1;
		std::cout << diam;
		std::cout << diam1;
		std::cout << diam2;
	}
	printSeparator();
}

void testParentPublicFunctions()
{
	std::cout << YELLOW << "Test Public function in ClapTrap Class" << RESET << std::endl;
	{
		ClapTrap clap("Pai");
		ScavTrap scav("FilhoScav");
		FragTrap frag("FilhoFrag");
		DiamondTrap diam("FilhoDiam");

		clap.setAttackDamage(1);
		clap.beRepaired(20);
		attackAnother(clap, scav);

		attackAnother(scav, clap);
		scav.beRepaired(100);
		scav.setAttackDamage(1000);

		frag.beRepaired(50);
		frag.setAttackDamage(500);
		attackAnother(frag, scav);

		diam.beRepaired(50);
		diam.setAttackDamage(5000);
		attackAnother(diam, frag);

		std::cout << clap;
		std::cout << scav;
		std::cout << frag;
		std::cout << diam;
	}
	printSeparator();
}

void testChildPublicFunction()
{
	{
		std::cout << YELLOW << "Test Public function in Diamond Class" << RESET << std::endl;
		DiamondTrap frag("DiamondTrapper");
		frag.attack("Pai");
		std::cout << frag;
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
