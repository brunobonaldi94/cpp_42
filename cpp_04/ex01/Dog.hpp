/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:26:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/20 21:33:57 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog();
		~Dog();
		Dog(Dog const &src);
		Dog & operator=(Dog const &rhs);
		
				
		Brain *getBrain( void ) const;
		void setBrain(Brain *brain);
		void makeSound() const;

	private:
		Brain *brain;
};

#endif
