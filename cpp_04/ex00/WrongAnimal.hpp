/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:22:37 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/15 22:48:25 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>

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
		std::string type;
};

#endif
