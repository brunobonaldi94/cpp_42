/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:46 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/05 22:39:38 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap();

		ClapTrap & operator=(ClapTrap const &rhs);
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		
		std::string getName( void ) const;
		void setName(std::string const name);
		void setHitPoints(int const hitPoints);
		int getHitPoints( void ) const;
		void setEnergyPoints(int const energyPoints);
		int getEnergyPoints( void ) const;
		void setAttackDamage(int const attackDamage);
		int getAttackDamage( void ) const;

	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

};

#endif
