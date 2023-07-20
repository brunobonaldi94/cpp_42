/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:48:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/20 19:34:24 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	try 
	{
		int arr[] = {1, 2, 3, 4, 5};
		std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
		int i = 6;
		int &t = easyfind(v, i);
		std::cout << t << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
