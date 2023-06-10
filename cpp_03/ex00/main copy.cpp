/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:23 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/09 21:30:49 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <unistd.h>

int	createRandomNumber(int min_range, int max_range)
{
	int random = min_range + (rand() % (max_range - min_range + 1));

	return random;
}

void	clapTrapAttackAnother(ClapTrap* & ct1, ClapTrap* & ct2, int how_many_times)
{
	for (int i = 0; i < how_many_times; i++)
	{
		ct1->attack(ct2->getName());
		ct2->takeDamage(ct1->getAttackDamage());
	}
	
}

std::vector<ClapTrap *> createClapTraps(int const qty)
{
	std::string names[] = {"Julia", "Bruno", "Giovanni", "Claudia", "Ana", "Marcos", "Mariza", "Renato", "Rafael", "Jose"};
	size_t names_size = sizeof(names) / sizeof(names[0]);
	std::vector<ClapTrap *> cps;
	for (int i = 0; i < qty; i++)
	{
		ClapTrap * cp = new ClapTrap(names[i % names_size]);
		cps.push_back(cp);
	}
	return cps;
}

void	freeClapTraps(std::vector<ClapTrap *> &cps)
{
	std::vector<ClapTrap *>::iterator it;

	for (it = cps.begin(); it != cps.end(); ++it)
		delete (*it);
}

void	setAttackDamages(std::vector<ClapTrap *> &cps)
{
	std::vector<ClapTrap *>::iterator it;

	for (it = cps.begin(); it != cps.end(); ++it)
	{
		int randomNumber = createRandomNumber(1, cps.size());
		(*it)->setAttackDamage(randomNumber);
	}
}

void repairClapTraps(std::vector<ClapTrap *> &cps)
{
	std::vector<ClapTrap *>::iterator it;
	for (it = cps.begin(); it != cps.end(); ++it)
	{
		int randomNumber = createRandomNumber(1, cps.size());
		(*it)->beRepaired(randomNumber);
	}
}

void	createWar(std::vector<ClapTrap *> & cps)
{
	setAttackDamages(cps);
	repairClapTraps(cps);
	for (size_t i = 0; i < cps.size() - 2; i+=2)
	{
		int qty_attacks = (double)cps[i + 1]->getHitPoints() / (double)cps[i]->getAttackDamage();
		clapTrapAttackAnother(cps[i], cps[i + 1], ceil(qty_attacks));
	}
}

int main( void )
{
	int const qty = 10;
	srand(static_cast<unsigned int>(time(NULL)));

	std::vector<ClapTrap *> cps = createClapTraps(qty);
	createWar(cps);
	freeClapTraps(cps);
	return 0;
}
