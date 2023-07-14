/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:18:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/13 23:41:33 by bbonaldi         ###   ########.fr       */
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
		std::cout << "---O---" << std::endl;
		ScalarConverter::converter("0");
		std::cout << "---122---" << std::endl;
		ScalarConverter::converter("122");
		std::cout << "---42.00f---" << std::endl;
		ScalarConverter::converter("42.00f");
		std::cout << "---42.00---" << std::endl;
		ScalarConverter::converter("42.00");
		std::cout << "---nan---" << std::endl;
		ScalarConverter::converter("nan");
		std::cout << "---nanf---" << std::endl;
		ScalarConverter::converter("nanf");
		std::cout << "---inff---" << std::endl;
		ScalarConverter::converter("-inff");
		std::cout << "---+inf---" << std::endl;
		ScalarConverter::converter("+inf");
		std::cout << "---INT_MAX +2147483647+ ---" << std::endl;
		ScalarConverter::converter("-2147483648");
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
