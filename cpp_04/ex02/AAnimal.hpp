/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:22:37 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/20 21:40:20 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(AAnimal const &src);

		AAnimal & 		operator=(AAnimal const &rhs);
		void			setType(std::string type);
		std::string		getType( void ) const;
		virtual void	makeSound( void ) const = 0;
	private:
		std::string type;
};

#endif
