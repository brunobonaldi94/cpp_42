/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:18:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/02 14:17:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void printSeparator()
{
	std::cout << std::string(50, '-') << std::endl;
}

void test1()
{
	{
		std::cout << "Test 1: No Exception will be thrown" << std::endl;
		try
		{
			Bureaucrat b0("b0", 2);
			b0.incrementGrade();
			std::cout << b0;
			Bureaucrat b1("b1", 149);
			b1.decrementGrade();
			std::cout << b1;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	printSeparator();
}

void test2()
{
	{
		std::cout << "Test 2: Too High Exeception will be thrown using Constructor" << std::endl;
		try
		{
			Bureaucrat b2("b2", 0);
			std::cout << b2;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	printSeparator();
}

void test3()
{
	{
		std::cout << "Test 3: Too High Exeception will be thrown using incrementGrade" << std::endl;
		try
		{
			Bureaucrat b3("b3", 10);
			for (int i = 0; i < 10; i++)
				b3.incrementGrade();
			std::cout << b3;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	printSeparator();
}

void test4()
{
	{
		std::cout << "Test 4: Too Low Exeception will be thrown using Constructor" << std::endl;
		try
		{
			Bureaucrat b4("b4", 151);
			std::cout << b4;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	printSeparator();
}

void test5()
{
	std::cout << "Test 5: Too Low Exeception will be thrown" << std::endl;
	try
	{
		Bureaucrat b5("b5", 141);
		for (int i = 0; i < 10; i++)
			b5.decrementGrade();
		std::cout << b5;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}


int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
}
