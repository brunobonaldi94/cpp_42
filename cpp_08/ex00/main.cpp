/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:48:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/26 17:55:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

typedef void (*tFunction)(void);

void printSeparator()
{
	std::cout << std::string(50, '-') << std::endl;
}

template<class TContainer>
void printContainer(TContainer &cont)
{
	std::cout << GREEN << "[ ";
	for (typename TContainer::iterator it = cont.begin(); it != cont.end(); it++)
	{
		std::cout << *it;
		if (it != --cont.end())
			std::cout << ", ";
	}
	std::cout << " ]" << RESET << std::endl;
}

template<class TContainer>
void testFound()
{
	std::srand(time(NULL));
	int i = std::rand() % 6;
	int arr[] = {0, 1, 2, 3, 4, 5};
	TContainer container(arr, arr + sizeof(arr) / sizeof(int));
	printContainer(container);
	std::cout << "value to find : " << i << std::endl;
	typename TContainer::iterator it = easyfind(container, i);
	std::cout << "value found: " << *it << std::endl;
	container.push_back(6);
	it = easyfind(container, 6);
	std::cout << "value found: " << *it << std::endl;
}

template<class TContainer>
void testNotFound()
{
	std::srand(time(NULL));
	int i = (std::rand() % 10) + 6;
	int arr[] = {0, 1, 2, 3, 4, 5};

	TContainer container(arr, arr + sizeof(arr) / sizeof(int));
	printContainer(container);

	std::cout << "value to find : " << i << std::endl;
	typename TContainer::iterator it = easyfind(container, i);
	std::cout << "value : " << *it << std::endl;
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
	testFunctionAndNames["Test Found - Vector"] = testFound<std::vector<int> >;
	testFunctionAndNames["Test Found - Deque"] = testFound<std::deque<int> >;
	testFunctionAndNames["Test Found - List"] = testFound<std::list<int> >;
	testFunctionAndNames["Test Not Found - Vector"] = testNotFound<std::vector<int> >;
	testFunctionAndNames["Test Not Found - Deque"] = testNotFound<std::deque<int> >;
	testFunctionAndNames["Test Not Found - List"] = testNotFound<std::list<int> >;
	
	std::map<std::string, tFunction>::iterator tF;
	int i;
	for (i = 1, tF = testFunctionAndNames.begin(); tF != testFunctionAndNames.end(); i++, tF++)
		runTestFunction(*tF, i);
	return 0;
}

