/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:02:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/18 22:22:05 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printSeparator()
{
	std::cout << std::string(50, '-') << std::endl;
}

template< typename T >
void print( T const & x )
{
  std::cout << x << std::endl;
  return;
}

template <typename T>
void runTestFunction(int index, std::string testName, T *arr, size_t size, void(*fn)(T const &value))
{
	std::cout << YELLOW << "TEST-" << index << ": " << testName <<  RESET << std::endl;
	iter(arr, size, fn);
	printSeparator();
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	runTestFunction<int>(1, "Int", arr, 5, print<const int>);
	
	std::string arr2[] = { "1", "2", "3", "4", "5" };
	runTestFunction<std::string>(2, "String", arr2, 5, print<const std::string>);
	
	float arr3[] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
	runTestFunction<float>(3, "Float", arr3, 5, print<const float>);

	double arr4[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	runTestFunction<double>(4, "Double", arr4, 5, print<const double>);

	return 0;
}
