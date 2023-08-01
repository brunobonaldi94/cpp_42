/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:09:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/31 21:09:19 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "You must run with one arg" << std::endl;
		return (-1);
	}
	RPN rpn;
	rpn.Calculate(argv[1]);
	return (0);
}
