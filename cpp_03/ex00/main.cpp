/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/28 21:23:53 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void testDefaultConstructor()
{
	std::cout << YELLOW << "DefaultConstructor" << RESET << std::endl;
	ClapTrap clap;
}

void testNamedConstructor()
{
	std::cout << YELLOW << "Testing Named Constructor" <<  RESET << std::endl;
	std::string name = "Clapper";
	ClapTrap clap(name);
}

void testCopyConstructorAndAssignmentOperator()
{
	std::cout << YELLOW << "Testing Copy Constructor And Assignment Operator" <<  RESET << std::endl;
	std::string name = "Clapper2";
	ClapTrap clap(name);
	ClapTrap clap1(clap);
	ClapTrap clap3;
	clap3 = clap1;
}

void testPublicFunction()
{
	std::cout << YELLOW << "Testing Attack function" <<  RESET << std::endl;
	ClapTrap atacante("Atacante");
	ClapTrap defensor("Defensor");
	atacante.setAttackDamage(1);
	defensor.beRepaired(10);
	while (!defensor.NoMorePoints() && !atacante.NoMorePoints())
	{
		atacante.attack(defensor.getName());
		defensor.takeDamage(atacante.getAttackDamage());
	}
	std::cout << atacante;
	std::cout << defensor;
}

int main( void )
{
	testDefaultConstructor();
	printSeparator();
	testNamedConstructor();
	printSeparator();
	testCopyConstructorAndAssignmentOperator();
	printSeparator();
	testPublicFunction();
	printSeparator();
	return 0;
}
