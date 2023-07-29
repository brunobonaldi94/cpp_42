/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:09:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/28 23:38:40 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: btc can only run with one arg (filename)" << RESET << std::endl;
		return (1);
	}
	std::string filename(argv[1]);
	BitcoinExchange btc(filename);
	btc.DoExchange();
	return (0);
}
