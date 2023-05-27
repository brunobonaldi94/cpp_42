/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:41:13 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/26 22:44:28 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() { }
Harl::~Harl() { }

void	Harl::complain( std::string level )
{
	int const size = 4;
	std::string levels[size] = { "debug", "info", "warning", "error" };
	void (Harl::*complains[size])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	for (int i = 0; i < size ; i++)
	{
		if (level == levels[i])
			(this->*complains[i])();
	}
}

void	Harl::debug( void )
{
	std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
}
void	Harl::info( void )
{
	std::cout << BLUE << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << BLUE << std::endl;

}
void	Harl::warning( void )
{
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << YELLOW << std::endl;

}
void	Harl::error( void )
{
	std::cout << RED << "This is unacceptable! I want to speak to the manager now" << RESET << std::endl;

}
