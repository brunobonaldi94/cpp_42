/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:09:17 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/25 21:52:18 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "Container.hpp"


void printSeparator();
void testPDF(void);
typedef void (*tFunction)(void);
void runTestFunction(std::pair<std::string, tFunction> testFunAndNames, int index);
void printSeparator()
{
	std::cout << std::string(100, '-') << std::endl;
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

void testPDF(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}


template <typename T, class TContainer>
void testOtherContainers(void)
{
	std::cout << typeid(TContainer).name() << std::endl;
	Container<T, TContainer> container;
	container.push(5);
	container.push(17);
	std::cout << container.top() << std::endl;
	container.pop();
	std::cout << container.size() << std::endl;
	container.push(3);
	container.push(5);
	container.push(737);
	container.push(0);
	typename Container<T, TContainer>::iterator it = container.begin();
	typename Container<T, TContainer>::iterator ite = container.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int	main(void)
{
	std::map<std::string, tFunction> testFunctionAndNames;
	testFunctionAndNames["Test A PDF"] = testPDF;
	testFunctionAndNames["Test Other Containers - List"] = testOtherContainers<int, std::list<int> >;
	testFunctionAndNames["Test Other Containers - Deque"] = testOtherContainers<int, std::deque<int> >;
	testFunctionAndNames["Test Other Containers - Vector"] = testOtherContainers<int, std::vector<int> >;
	
	std::map<std::string, tFunction>::iterator tF;
	int i;
	for (i = 1, tF = testFunctionAndNames.begin(); tF != testFunctionAndNames.end(); i++, tF++)
		runTestFunction(*tF, i);
	return 0;
}
