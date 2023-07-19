/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:18:35 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/18 20:53:35 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void printSeparator()
{
	std::cout << std::string(50, '-') << std::endl;
}

template <typename T>
void testFunctions(T &a, T&b)
{
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap<T>(a, b);
	std::cout << YELLOW << "SWAP" << RESET << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

template <typename T>
void runTestFunction(int index, std::string testName, T* args)
{
	std::cout << YELLOW << "TEST-" << index << ": " << testName <<  RESET << std::endl;
	testFunctions<T>(args[0], args[1]);
	printSeparator();
}

int	main(void)
{
	int index = 1;
	int arg1[2] = {2, 3};
	runTestFunction<int>(index++, "Int", arg1);
	std::string arg2[2] = {"chaine1", "chaine2"};
	runTestFunction<std::string>(index++, "String", arg2);
	float arg3[2] = {1.1f, 2.1f};
	runTestFunction<float>(index++, "Float", arg3);
	double arg4[2] = {1.2, 2.2};
	runTestFunction<double>(index++, "Double", arg4);
	return 0;
}
