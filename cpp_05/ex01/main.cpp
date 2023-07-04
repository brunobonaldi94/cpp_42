/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:18:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/03 23:27:11 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void printSeparator()
{
	std::cout << std::string(50, '-') << std::endl;
}

void testNoException()
{
	try
	{
		Form f0("form0", 2);
		std::cout << f0;
		Form f1("form1", 149);
		std::cout << f1;
		Form f2(f1);
		std::cout << "f2: "<< f2;
		Form f3;
		f3 = f2;
		std::cout << "f3: " << f3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testGradeTooHighExceptionByConstructor()
{
	try
	{
		Form f2("form2", 0);
		std::cout << f2;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void testFormBeSignedNoException()
{
	try
	{
		Form f3("form3", 10);
		Bureaucrat b1("b1", 1);
		f3.beSigned(b1);
		std::cout << f3;
		
		Form f4("form4", 10);
		Bureaucrat b2("b2", 10);
		f4.beSigned(b2);
		std::cout << f4;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void testFormGradeTooLowExceptionByConstructor()
{
	try
	{
		Form f5("form5", 151);
		std::cout << f5;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void testGradeTooLowExceptionByBeSigned()
{
	try
	{
		Form f6("form6", 10);
		Bureaucrat b4("b4", 11);
		f6.beSigned(b4);
		std::cout << f6;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void testSigForm()
{
	try
	{
		Bureaucrat b6("b6", 141);
		Form f7("form7", 142);
		b6.signForm(f7);
		std::cout << f7;

		Bureaucrat b7("b7", 140);
		Form f8("form8", 1);
		b7.signForm(f8);
		std::cout << f8;
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
	int const testNumbers = 6;
	void (*testFunctions[testNumbers])(void) = {
		testNoException,
		testGradeTooHighExceptionByConstructor,
		testFormBeSignedNoException,
		testFormGradeTooLowExceptionByConstructor,
		testGradeTooLowExceptionByBeSigned,
		testSigForm,
	};
	std::string testNames[testNumbers] = {
		"No Exception", 
		"Grade Too High Exception by Constructor", 
		"Form BeSigned No Exception", 
		"Grade Too Low Exception by Constructor", 
		"Sign Form"
	};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}
