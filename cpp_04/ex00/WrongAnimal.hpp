/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:22:37 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/06 19:46:27 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>

# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(WrongAnimal const &src);

		WrongAnimal & 	operator=(WrongAnimal const &rhs);
		void			setType(std::string type);
		std::string		getType( void ) const;
		void			makeSound( void ) const;
	private:
		std::string _type;
};

#endif
