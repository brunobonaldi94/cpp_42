/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:14:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/26 23:17:26 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl reclamao;

	if (argc != 2)
	{
		std::cout << "Harl only accepts one arg" << std::endl;
		return (1);
	}
	reclamao.complain(argv[1]);
	return (0);
}
