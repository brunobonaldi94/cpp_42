/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/03 20:50:28 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


void attackAnother(ClapTrap &attacker, ClapTrap &defender, std::string name)
{
	attacker.attack(name);
	defender.takeDamage(attacker.getAttackDamage());
}

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void testConstructors()
{
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

void testCopyConstructorAndAssignmentOperator()
{
	DiamondTrap diam("DiamondTrapper");
	DiamondTrap diam1(diam);
	DiamondTrap diam2;
	diam2 = diam1;
	std::cout << diam;
	std::cout << diam1;
	std::cout << diam2;
}

void testParentPublicFunctions()
{
	ClapTrap clap("ClapParent");
	ScavTrap scav("ScavChild");
	FragTrap frag("FragChild");
	DiamondTrap diam("DiamChild");

	clap.setAttackDamage(1);
	clap.beRepaired(20);
	attackAnother(clap, scav, scav.getName());

	attackAnother(scav, clap, clap.getName());
	scav.beRepaired(100);
	scav.setAttackDamage(1000);

	frag.beRepaired(50);
	frag.setAttackDamage(500);
	attackAnother(frag, scav, scav.getName());

	diam.beRepaired(50);
	diam.setAttackDamage(5000);
	attackAnother(diam, frag, frag.getName());

	attackAnother(clap, diam, diam.getCurrentName());

	std::cout << clap;
	std::cout << scav;
	std::cout << frag;
	std::cout << diam;
}

void testChildPublicFunction()
{
	DiamondTrap diam("DiamondTrapper");
	diam.whoAmI();
	std::cout << diam;
}

void testVirtualDestructor()
{
	DiamondTrap *diam = new DiamondTrap("DiamondTrapper");
	ClapTrap *clap = diam;
	delete clap;
}

void runTestFunction(void (*test)(void), int index, std::string testName)
{
	std::cout << YELLOW << "TEST-" << index << ": " << testName <<  RESET << std::endl;
	test();
	printSeparator();
}

int main( void )
{
	int const testNumbers = 5;
	void (*testFunctions[testNumbers])(void) = {testConstructors, testCopyConstructorAndAssignmentOperator, testParentPublicFunctions, 
	testChildPublicFunction, testVirtualDestructor};
	std::string testNames[testNumbers] = {"Constructors", "Copy Constructor and Assignment Operator", "Parent Public Functions",
	 "Child Public Functions", "Virtual Destructor"};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}
