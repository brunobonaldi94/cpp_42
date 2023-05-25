/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:19:00 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 21:39:32 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB();
		HumanB( std::string name );
		~HumanB();
		
		std::string	getName( void ) const;
		void		setName( std::string const name );
		Weapon*		getWeapon() const;
		void		setWeapon( Weapon &weapon);

		void	attack( void );

	private:
		std::string	name;
		Weapon *weapon;
};

#endif
