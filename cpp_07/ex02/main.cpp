/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:32:26 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/19 22:02:21 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void testPdf()
{
	 Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << numbers;
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			std::exit(1);
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
}

void testString()
{
	Array<std::string> str(7);
	str[0] = "Hello";
	str[1] = "World";
	str[2] = "!";
	str[3] = "How";
	str[4] = "Are";
	str[5] = "You";
	str[6] = "?";
	std::cout << str;

	Array<std::string> str2(str);
	std::cout << str2;
	if (&str2[0] == &str[0])
		std::cout << "str2[0] == str[0: address" << &str2[0] << std::endl;
	if (str2[0] == str[0])
		std::cout << "str2[0] == str[0]: " << str[0] << std::endl;
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
		testPdf,
		testString
	};
	std::string testNames[testNumbers] = {
		"PDF",
		"Test String"
	};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}
