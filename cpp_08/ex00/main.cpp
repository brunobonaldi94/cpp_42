/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:48:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/20 23:50:48 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void printSeparator()
{
	std::cout << std::string(50, '-') << std::endl;
}

template<class TContainer>
void testFound()
{
	int arr[] = {1, 2, 3, 4, 5};
	TContainer container(arr, arr + sizeof(arr) / sizeof(int));
	int i = 2;
	typename TContainer::iterator it = easyfind(container, i);
	std::cout << "value : " << *it << std::endl;
	container.push_back(6);
	it = easyfind(container, 6);
	std::cout << "value : " << *it << std::endl;
}

template<class TContainer>
void testNotFound()
{
	int arr[] = {1, 2, 3, 4, 5};
	TContainer vec(arr, arr + sizeof(arr) / sizeof(int));
	int i = 6;
	typename TContainer::iterator it = easyfind(vec, i);
	std::cout << "value : " << *it << std::endl;
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

int	main(void)
{
	int const testNumbers = 6;
	void (*testFunctions[testNumbers])(void) = {
		testFound<std::vector<int> >,
		testFound<std::deque<int> >,
		testFound<std::list<int> >,
		testNotFound<std::vector<int> >,
		testNotFound<std::deque<int> >,
		testNotFound<std::list<int> >
	};
	std::string testNames[testNumbers] = {
		"Test Found - Vector",
		"Test Found - Deque",
		"Test Found - List",
		"Test Found - Vector",
		"Test Not Found - Deque",
		"Test Not Found - List"
	};
	for (int i = 0; i < testNumbers; i++)
		runTestFunction(testFunctions[i], i + 1, testNames[i]);
	return 0;
}

