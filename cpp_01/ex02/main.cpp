/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:43:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 18:53:10 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << std::left <<std::setw(50) << "memory address of brain by variable: " << &brain << std::endl;
	std::cout << std::left << std::setw(50) << "memory address of brain by stringPTR: " << stringPTR << std::endl;
	std::cout << std::left <<std::setw(50) << "memory address of brain by stringREF: " << &stringREF << std::endl;

	std::cout << std::left <<std::setw(50) << "value of brain by variable: " << brain << std::endl;
	std::cout << std::left << std::setw(50) << "valye of brain by stringPTR: " << *stringPTR << std::endl;
	std::cout << std::left <<std::setw(50) << "value of brain by stringREF: " << stringREF << std::endl;


	return (0);
}
