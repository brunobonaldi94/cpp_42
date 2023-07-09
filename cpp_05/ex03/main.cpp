/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:18:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/08 23:40:18 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"


void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void testNoException()
{
	try
	{
		int const formQty = 3;
		std::string formNames[formQty] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
		};
		Intern intern;
		for (int i = 0; i < formQty; i++)
		{
			AForm *form = intern.makeForm(formNames[i], "target_" + Intern::castIntToString(i + 1));
			std::cout << *form << std::endl;
			delete form;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void testFormNotFoundException()
{
	try
	{
		Intern intern;
		AForm *form = intern.makeForm("random form", "targetFoo");
		std::cout << *form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void runTestFunction(void (*test)(void), int index, std::string testName)
{
	std::cout << YELLOW << "TEST-" << index << ": " << testName <<  RESET << std::endl;
	test();
	printSeparator();
}

int	main(void)
{
	int const testNumbers = 2;
	void (*testFunctions[testNumbers])(void) = {
		testNoException,
		testFormNotFoundException
	};
	std::string testNames[testNumbers] = {
		"No Exception",
		"Form Not Found Exception"
	};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}


