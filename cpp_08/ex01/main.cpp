/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:09:17 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/25 21:52:33 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <map>

void printSeparator();
void printSpanFunctions(Span &sp);
void testPDF(void);
void testAddMultiple(void);
void AddSeveralNumbers(int n);
void testWithSeveralSequencialNumbers(void);
void testAddMoreThanN(void);
typedef void (*tFunction)(void);
void runTestFunction(std::pair<std::string, tFunction> testFunAndNames, int index);

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

void runTestFunction(std::pair<std::string, tFunction> testFunAndNames, int index)
{
	std::cout << YELLOW << "TEST-" << index << ": " << testFunAndNames.first <<  RESET << std::endl;
	try 
	{
		testFunAndNames.second();
	} catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	printSeparator();
}

int	main(void)
{
	std::map<std::string, tFunction> testFunctionAndNames;
	testFunctionAndNames["Test A PDF"] = testPDF;
	testFunctionAndNames["Test Add Multiple"] = testAddMultiple;
	testFunctionAndNames["Test With Several Numbers"] = testWithSeveralSequencialNumbers;
	testFunctionAndNames["Test Add More Than N"] = testAddMoreThanN;
	
	std::map<std::string, tFunction>::iterator tF;
	int i;
	for (i = 1, tF = testFunctionAndNames.begin(); tF != testFunctionAndNames.end(); i++, tF++)
		runTestFunction(*tF, i);
	return 0;
}
