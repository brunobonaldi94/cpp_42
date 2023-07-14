/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:18:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/12 18:56:04 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void tryToSignForm(AForm &form, Bureaucrat &bureaucrat)
{
	bureaucrat.signForm(form);
	std::cout << form;
}

void tryExecuteForm(AForm &form, Bureaucrat &bureaucrat)
{
	bureaucrat.executeForm(form);
	std::cout << form;
}

void tryToSignAndExecuteForm(AForm &form, Bureaucrat &bureaucrat)
{
	std::cout << bureaucrat;
	std::cout << form;
	tryToSignForm(form, bureaucrat);
	tryExecuteForm(form, bureaucrat);
}

void testNoException()
{
	try
	{
		int const formQty = 3;

		ShrubberyCreationForm *f0 = new ShrubberyCreationForm("form0");
		RobotomyRequestForm *f1 = new RobotomyRequestForm("form1");
		PresidentialPardonForm *f2 = new PresidentialPardonForm("form2");
		
		AForm *forms[formQty] = { f0, f1, f2 };

		for (int i = 0; i < formQty; i++)
		{
			Bureaucrat b("b", forms[i]->getExec());
			tryToSignAndExecuteForm(*(forms[i]), b);
			delete forms[i];
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void testFormBeSignedException()
{
	try
	{
		int const formQty = 3;
		int const lowGrade = 150;

		ShrubberyCreationForm *f0 = new ShrubberyCreationForm("form0");
		RobotomyRequestForm *f1 = new RobotomyRequestForm("form1");
		PresidentialPardonForm *f2 = new PresidentialPardonForm("form2");

		AForm *forms[formQty] = { f0, f1, f2 };
		for (int i = 0; i < formQty; i++)
		{
			Bureaucrat b("b", lowGrade);
			tryToSignAndExecuteForm(*(forms[i]), b);
			delete forms[i];
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void testFormBeExecutedException()
{
	try
	{
		int const formQty = 3;

		ShrubberyCreationForm *f0 = new ShrubberyCreationForm("form0");
		RobotomyRequestForm *f1 = new RobotomyRequestForm("form1");
		PresidentialPardonForm *f2 = new PresidentialPardonForm("form2");

		AForm *forms[formQty] = { f0, f1, f2 };
		for (int i = 0; i < formQty; i++)
		{
			Bureaucrat b("b", forms[i]->getGrade());
			tryToSignAndExecuteForm(*(forms[i]), b);
			delete forms[i];
		}
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
	int const testNumbers = 3;
	void (*testFunctions[testNumbers])(void) = {
		testNoException,
		testFormBeSignedException,
		testFormBeExecutedException
	};
	std::string testNames[testNumbers] = {
		"No Exception", 
		"Form BeSigned Exception",
		"Form BeExecuted Exception"
	};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}


