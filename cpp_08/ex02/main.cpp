/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:09:17 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/24 22:21:36 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>

void printSeparator();
void printSpanFunctions(Span &sp);
void testPDF(void);
void testAddMultiple(void);
void runTestFunction(void (*test)(void), int index, std::string testName);
void AddSeveralNumbers(int n);
void testWithSeveralSequencialNumbers(void);
void testAddMoreThanN(void);

int	main(void)
{
	int const testNumbers = 4;
	void (*testFunctions[testNumbers])(void) = {
		testPDF,
		testAddMultiple,
		testWithSeveralSequencialNumbers,
		testAddMoreThanN
	};
	std::string testNames[testNumbers] = {
		"Test PDF",
		"Test Add Multiple",
		"Test With Several Numbers",
		"Test Add More Than N"
	};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}

void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
}

void printSpanFunctions(Span &sp)
{
	sp.printShortestSpan();
	sp.printLongestSpan();
}

void testPDF(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	printSpanFunctions(sp);
}

void testAddMultiple(void)
{
	int const size = 5;
	int arr[size] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + size);
	Span sp = Span(size);
	sp.addRange(vec.begin(), vec.end());
	printSpanFunctions(sp);
}

void AddSeveralNumbers(int n)
{
	int const size = n;
	int arr[size];
	for (int i = 0; i < size; i++)
		arr[i] = i;
	std::vector<int> vec(arr, arr + size);
	Span sp = Span(size);
	sp.addRange(vec.begin(), vec.end());
	printSpanFunctions(sp);
}

void testWithSeveralSequencialNumbers(void)
{
	AddSeveralNumbers(10000);
	AddSeveralNumbers(500000);
	AddSeveralNumbers(1000000);
}

void testAddMoreThanN(void)
{
	int const size = 5;
	int arr[size] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + size);
	Span sp = Span(size);
	sp.addRange(vec.begin(), vec.end());
	sp.addNumber(6);
}

void runTestFunction(void (*test)(void), int index, std::string testName)
{
	std::cout << YELLOW << "TEST-" << index << ": " << testName <<  RESET << std::endl;
	try 
	{
		test();
	} catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	printSeparator();
}
