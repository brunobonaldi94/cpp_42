/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:26:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/15 22:43:54 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_H
#define WRONG_CAT_H

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal 
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat const &src);
		WrongCat & operator=(WrongCat const &rhs);
		
		void makeSound() const;
};

#endif
