/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/01 22:35:21 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
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
		FragTrap frag;
		std::cout << frag;
		FragTrap frag1("FragTrapper");
		std::cout << frag1;
	}
	printSeparator();
}

void testCopyConstructorAndAssignmentOperator()
{
	{
		std::cout << YELLOW << "Testing Copy Constructor And Assignment Operator" <<  RESET << std::endl;
		FragTrap frag("FragTrapper");
		FragTrap frag1(frag);
		FragTrap frag2;
		frag2 = frag1;
		std::cout << frag;
		std::cout << frag1;
		std::cout << frag2;
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

		clap.setAttackDamage(1);
		clap.beRepaired(20);
		attackAnother(clap, scav);

		attackAnother(scav, clap);
		scav.beRepaired(100);
		scav.setAttackDamage(1000);

		frag.beRepaired(50);
		frag.setAttackDamage(500);
		attackAnother(frag, scav);

		std::cout << clap;
		std::cout << scav;
		std::cout << frag;
	}
	printSeparator();
}

void testChildPublicFunction()
{
	{
		std::cout << YELLOW << "Test Public function in FragTrap Class" << RESET << std::endl;
		FragTrap frag("FragTrapper");
		frag.attack("Pai");
		frag.highFivesGuys();
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
