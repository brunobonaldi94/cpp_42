/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:09:17 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/26 17:54:32 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

typedef void (*tFunction)(void);

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

void testAddMoreThanNByAddNumber(void)
{
	int const size = 5;
	int arr[size] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + size);
	Span sp = Span(size);
	sp.addRange(vec.begin(), vec.end());
	sp.addNumber(6);
}

void testAddMoreThanNByAddRange(void)
{
	int const size = 5;
	int arr[size] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + size);
	Span sp = Span(size);
	sp.addRange(vec.begin(), vec.end());
	int arr2[size] = {6, 7, 8, 9, 10};
	std::vector<int> vec1(arr2, arr2+ size);
	sp.addRange(vec1.begin(), vec1.end());
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
	testFunctionAndNames["Test Add More Than N by Add Number"] = testAddMoreThanNByAddNumber;
	testFunctionAndNames["Test Add More Than N by Add Range"] = testAddMoreThanNByAddRange;
	testFunctionAndNames["Test Add Multiple"] = testAddMultiple;
	testFunctionAndNames["Test With Several Numbers"] = testWithSeveralSequencialNumbers;
	
	std::map<std::string, tFunction>::iterator tF;
	int i;
	for (i = 1, tF = testFunctionAndNames.begin(); tF != testFunctionAndNames.end(); i++, tF++)
		runTestFunction(*tF, i);
	return 0;
}
