/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:18:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/15 16:52:10 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printSeparator(int qty, char c)
{
	std::cout << std::string(qty, c) << std::endl;
}

void runEachTests(std::string *params, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		std::cout << BLUE << "param: " << params[i] << RESET << std::endl;
		printSeparator(50, '-');
		ScalarConverter::converter(params[i]);
		printSeparator(100, '=');
	}
}

void runAllTests()
{
	try
	{
		std::string params[] = {
			"0",
			"42",
			"128",
			"42.0f",
			"42.0",
			"42.1",
			"f",
			"nan",
			"nanf",
			"-inff",
			"+inf",
			"-inff",
			"inf",
			"inff",
			"-2147483648",
			"2147483647",
			"2147483648",
		};
		runEachTests(params, sizeof(params) / sizeof(params[0]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << YELLOW << "TEST: " << "All Testes" <<  RESET << std::endl;
	printSeparator(100, '~');
	runAllTests();
	return 0;
}
