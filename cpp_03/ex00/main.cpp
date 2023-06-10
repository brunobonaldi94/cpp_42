/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/10 15:02:52 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void testDefaultConstructor()
{
	ClapTrap clap;
}

void testNamedConstructor()
{
	std::string name = "Clapper";
	ClapTrap clap(name);
}

void testCopyConstructorAndAssignmentOperator()
{
	std::string name = "Clapper2";
	ClapTrap clap(name);
	ClapTrap clap1(clap);
	ClapTrap clap3 = clap1;
}

int main( void )
{
	testDefaultConstructor();
	printSeparator();
	testNamedConstructor();
	printSeparator();
	testCopyConstructorAndAssignmentOperator();
	printSeparator();
	return 0;
}
