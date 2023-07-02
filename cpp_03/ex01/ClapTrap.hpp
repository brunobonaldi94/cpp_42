/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:44:46 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/01 20:00:27 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>
#include <iomanip>

# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"


class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		virtual ~ClapTrap();

		ClapTrap & operator=(ClapTrap const &rhs);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getAllAttributes( void ) const;

		std::string getName( void ) const;
		void setName(std::string const name);
		std::string getClassName( void ) const;
		void setClassName(std::string const className);
		void setHitPoints(int const hitPoints);
		int getHitPoints( void ) const;
		void setEnergyPoints(int const energyPoints);
		int getEnergyPoints( void ) const;
		void setAttackDamage(int const attackDamage);
		int getAttackDamage( void ) const;

		bool NoMorePoints( void ) const;
		std::string getNameAndClassName( void ) const;

	protected:
		std::string _name;
		std::string _className;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};

std::ostream & operator<<(std::ostream & o, ClapTrap const & src);

#endif
