/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:18:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 12:53:47 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void runAllTests(std::string *params, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		std::cout << GREEN << "===" << params[i] << "===" << RESET << std::endl;
		ScalarConverter::converter(params[i]);
	}
}

void testNoException()
{
	try
	{
		std::string params[] = {
			"0",
			"128",
			"42",
			"42.0f",
			"42.0",
			"42.1",
			"nan",
			"nanf",
			"-inff",
			"+inf",
			"-2147483648",
			"2147483647"
		};
		runAllTests(params, sizeof(params) / sizeof(params[0]));
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
