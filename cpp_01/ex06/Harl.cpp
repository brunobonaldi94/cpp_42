/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:41:13 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/26 23:42:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() { }
Harl::~Harl() { }

void	Harl::complain( std::string level )
{
	int const size = 5;
	void (Harl::*complains[size])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::otherComplain };
	int	i = this->findComplainLevel(level);
	if (i == -1)
	{
		(this->*complains[size - 1])();
		return ;
	}
	for (; i < size; i++)
	{
		switch (i)
		{
			case 0:
				(this->*complains[i])();
				break;
			case 1:
				(this->*complains[i])();
				break;
			case 2:
				(this->*complains[i])();
				break;
			case 3:
				(this->*complains[i])();
				break;
			default:
				break;
		}
		std::cout << std::endl;
	}
}

int	Harl::findComplainLevel( std::string level)
{
	int const 	size = 4;
	std::string	levels[size] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int			i;

	for (i = 0; i < size; i++)
	{
		if (level == levels[i])
			break;
	}
	if (i == 4)
		return -1;
	return (i);
}

void	Harl::debug( void )
{	std::cout << GREEN << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
}
void	Harl::info( void )
{
	std::cout << BLUE << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << BLUE << std::endl;

}
void	Harl::warning( void )
{
	std::cout << YELLOW << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << YELLOW << std::endl;

}
void	Harl::error( void )
{
	std::cout << RED << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now" << RESET << std::endl;

}

void	Harl::otherComplain( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
