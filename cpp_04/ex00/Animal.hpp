/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:22:37 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/06 19:55:38 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

#include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(Animal const &src);

		Animal & 		operator=(Animal const &rhs);
		void			setType(std::string type);
		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;
	protected:
		std::string _type;
};

#endif
