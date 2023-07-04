/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/03 20:48:22 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void attackAnother(ClapTrap &attacker, ClapTrap &defender)
{
	attacker.attack(defender.getName());
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
	ScavTrap scav2("ScavTrapper");
	std::cout << scav2;
}

void testCopyConstructorAndAssignmentOperator()
{
	ScavTrap scav("ScavTrapper");
	ScavTrap scav1(scav);
	ScavTrap scav2;
	scav2 = scav1;
	std::cout << scav;
	std::cout << scav1;
	std::cout << scav2;
}

void testParentPublicFunctions()
{
	ClapTrap clap("Parent");
	ScavTrap scav("Child");
	clap.setAttackDamage(1);
	clap.beRepaired(20);
	attackAnother(clap, scav);
	attackAnother(scav, clap);
	scav.beRepaired(100);
	scav.setAttackDamage(1000);
	std::cout << clap;
	std::cout << scav;
}

void testChildPublicFunction()
{

	ScavTrap scav("ScavTrapper");
	scav.guardGate();
	std::cout << scav;
}

void testVirtualDestructor()
{
	ScavTrap *scav = new ScavTrap("Scavver");
	ClapTrap *clap = scav;
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
	void (*testFunctions[testNumbers])(void) = {testConstructors, testCopyConstructorAndAssignmentOperator,
	testParentPublicFunctions, testChildPublicFunction, testVirtualDestructor};
	std::string testNames[testNumbers] = {"Constructors", "Copy Constructor and Assignment Operator", "Parent Public Functions"
	, "Child Public Functions", "Virtual Destructor"};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}
