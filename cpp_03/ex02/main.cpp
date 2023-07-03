/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/03 20:27:59 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
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
	FragTrap frag;
	std::cout << frag;
	FragTrap frag1("FragTrapper");
	std::cout << frag1;
}

void testCopyConstructorAndAssignmentOperator()
{
	FragTrap frag("FragTrapper");
	FragTrap frag1(frag);
	FragTrap frag2;
	frag2 = frag1;
	std::cout << frag;
	std::cout << frag1;
	std::cout << frag2;
}

void testParentPublicFunctions()
{

	ClapTrap clap("Parent");
	ScavTrap scav("ScavChild");
	FragTrap frag("FragChild");
	
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

void testChildPublicFunction()
{
	FragTrap frag("FragTrapper");
	frag.highFivesGuys();
	std::cout << frag;
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
	void (*testFunctions[testNumbers])(void) = {testConstructors, testCopyConstructorAndAssignmentOperator, testParentPublicFunctions, testChildPublicFunction};
	std::string testNames[testNumbers] = {"Constructors", "Copy Constructor and Assignment Operator", "Parent Public Functions" , "Child Public Functions"};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}
