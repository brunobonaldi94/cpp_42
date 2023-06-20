/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:26:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/19 23:15:27 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal 
{
	public:
		Cat();
		~Cat();
		Cat(Cat const &src);
		Cat & operator=(Cat const &rhs);
		
		Brain *getBrain( void ) const;
		void setBrain(Brain *brain);
		void makeSound() const;
	
	private:
		Brain *brain;
};

#endif
