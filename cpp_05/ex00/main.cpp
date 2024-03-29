/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:18:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/03 22:56:42 by bbonaldi         ###   ########.fr       */
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
		Bureaucrat b0("b0", 2);
		b0.incrementGrade();
		std::cout << b0;
		Bureaucrat b1("b1", 149);
		b1.decrementGrade();
		std::cout << b1;
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
		Bureaucrat b2("b2", 0);
		std::cout << b2;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void testGradeTooHighExceptionByIncrementGrade()
{
	try
	{
		Bureaucrat b3("b3", 10);
		for (int i = 0; i < 10; i++)
			b3.incrementGrade();
		std::cout << b3;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}


void testGradeTooLowExceptionByConstructor()
{
	try
	{
		Bureaucrat b4("b4", 151);
		std::cout << b4;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void testGradeTooLowExceptionByDecrementGrade()
{
	std::cout << "Test 5: Too Low Exeception will be thrown" << std::endl;
	
	try
	{
		Bureaucrat b5("b5", 141);
		for (int i = 0; i < 10; i++)
			b5.decrementGrade();
		std::cout << b5;
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
	int const testNumbers = 5;
	void (*testFunctions[testNumbers])(void) = {
		testNoException,
		testGradeTooHighExceptionByConstructor,
		testGradeTooHighExceptionByIncrementGrade,
		testGradeTooLowExceptionByConstructor,
		testGradeTooLowExceptionByDecrementGrade
	};
	std::string testNames[testNumbers] = {
		"No Exception", 
		"Grade Too High Exception by Constructor", 
		"Grade Too High Exception By Increment Grade", 
		"Grade Too Low Exception by Constructor", 
		"Grade Too Low Exception By Decrement Grade", 
	};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}
