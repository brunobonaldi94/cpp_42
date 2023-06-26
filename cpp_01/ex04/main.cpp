/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:36:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/25 18:45:18 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

int	main( int argc, char *argv[] )
{
	if (argc != 4)
	{
		std::cout << "Usage: ./main <file> <s1> <s2>" << std::endl;
		return (0);
	}
	char* file_name = argv[1];
	char* s1 = argv[2];
	char* s2 = argv[3];
	MySed mysed(file_name, s1, s2);
	mysed.replaceS1byS2();
	return (0);
}
