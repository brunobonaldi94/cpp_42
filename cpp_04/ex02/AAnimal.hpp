/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:22:37 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/06 19:53:52 by bbonaldi         ###   ########.fr       */
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
		std::string _type;
};

#endif
