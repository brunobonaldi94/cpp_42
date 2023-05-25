/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:08:26 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/24 21:23:48 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA();

		std::string	getName( void ) const;
		void		setName( std::string const name );
		Weapon		getWeapon();
		void		setWeapon( Weapon const weapon);

		
		void	attack( void );

	private:
		std::string	name;
		Weapon&	weapon;
};

#endif
