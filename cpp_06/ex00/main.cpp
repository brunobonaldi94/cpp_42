/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:18:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/11 22:15:00 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printSeparator()
{
	std::cout << std::string(50, '-') << std::endl;
}

void testNoException()
{
	try
	{
		ScalarConverter::converter("0");
		ScalarConverter::converter("122");
		ScalarConverter::converter("42.00f");
		ScalarConverter::converter("42.00f");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
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
	int const testNumbers = 1;
	void (*testFunctions[testNumbers])(void) = {
		testNoException
	};
	std::string testNames[testNumbers] = {
		"No Exception", 
	};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}
