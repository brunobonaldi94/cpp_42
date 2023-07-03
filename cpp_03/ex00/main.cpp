/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/03 20:23:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void attackAnother(ClapTrap &attacker, ClapTrap &defender)
{
	attacker.attack(defender.getName());
	defender.takeDamage(attacker.getAttackDamage());
}

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void testDefaultConstructor()
{
	ClapTrap clap;
	std::cout << clap;

}

void testNamedConstructor()
{
	std::string name = "Clapper";
	ClapTrap clap(name);
	std::cout << clap;
}

void testCopyConstructorAndAssignmentOperator()
{
	ClapTrap clap("Clapper");
	ClapTrap clap1(clap);
	ClapTrap clap3;
	clap3 = clap1;
	std::cout << clap;
	std::cout << clap1;
	std::cout << clap3;
}

void testPublicFunction()
{
	ClapTrap attacker("Atacante");
	ClapTrap defender("Defensor");
	attacker.setAttackDamage(1);
	defender.beRepaired(10);
	while (!attacker.NoMorePoints())
		attackAnother(attacker, defender);
	std::cout << attacker;
	std::cout << defender;
}

void runTestFunction(void (*test)(void), int index, std::string testName)
{
	std::cout << YELLOW << "TEST-" << index << ": " << testName <<  RESET << std::endl;
	test();
	printSeparator();
}

int main( void )
{
	int const testNumbers = 4;
	void (*testFunctions[testNumbers])(void) = {testDefaultConstructor, testNamedConstructor, testCopyConstructorAndAssignmentOperator, testPublicFunction};
	std::string testNames[testNumbers] = {"Default Constructor", "Named Constructor", "Copy Constructor and Assignment Operator", "Public Function"};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}
