/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:18:37 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/05/23 22:26:52 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
	public:

		Zombie();
		Zombie( std::string const name );
		~Zombie();
		
		std::string	getName( void ) const;

		void	announce( void );

	private:
		std::string name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );


#endif
