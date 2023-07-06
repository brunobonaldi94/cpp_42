/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:18:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/05 23:14:18 by bbonaldi         ###   ########.fr       */
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
		ShrubberyCreationForm f0 = ShrubberyCreationForm("form0");
		Bureaucrat b0("b0", 1);

		tryToSignAndExecuteForm(f0, b0);
		RobotomyRequestForm f1 = RobotomyRequestForm("form1");
		tryToSignAndExecuteForm(f1, b0);
		PresidentialPardonForm f2 = PresidentialPardonForm("form1");
		tryToSignAndExecuteForm(f2, b0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// void testGradeTooHighExceptionByConstructor()
// {
// 	try
// 	{
// 		Form f2("form2", 0);
// 		std::cout << f2;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}
// }

// void testFormBeSignedNoException()
// {
// 	try
// 	{
// 		Form f3("form3", 10);
// 		Bureaucrat b1("b1", 1);
// 		f3.beSigned(b1);
// 		std::cout << f3;
		
// 		Form f4("form4", 10);
// 		Bureaucrat b2("b2", 10);
// 		f4.beSigned(b2);
// 		std::cout << f4;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}
// }

// void testFormGradeTooLowExceptionByConstructor()
// {
// 	try
// 	{
// 		Form f5("form5", 151);
// 		std::cout << f5;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}
// }

// void testGradeTooLowExceptionByBeSigned()
// {
// 	try
// 	{
// 		Form f6("form6", 10);
// 		Bureaucrat b4("b4", 11);
// 		f6.beSigned(b4);
// 		std::cout << f6;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}
// }

// void testSigForm()
// {
// 	try
// 	{
// 		Bureaucrat b6("b6", 141);
// 		Form f7("form7", 142);
// 		b6.signForm(f7);
// 		std::cout << f7;

// 		Bureaucrat b7("b7", 140);
// 		Form f8("form8", 1);
// 		b7.signForm(f8);
// 		std::cout << f8;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}
// }

void runTestFunction(void (*test)(void), int index, std::string testName)
{
	std::cout << YELLOW << "TEST-" << index << ": " << testName <<  RESET << std::endl;
	test();
	printSeparator();
}

int	main(void)
{
	int const testNumbers = 1;
	void (*testFunctions[testNumbers])(void) = {
		testNoException
		// ,
		// testGradeTooHighExceptionByConstructor,
		// testFormBeSignedNoException,
		// testFormGradeTooLowExceptionByConstructor,
		// testGradeTooLowExceptionByBeSigned,
		// testSigForm,
	};
	std::string testNames[testNumbers] = {
		"No Exception", 
		// "Grade Too High Exception by Constructor", 
		// "Form BeSigned No Exception", 
		// "Grade Too Low Exception by Constructor", 
		// "Sign Form"
	};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}


