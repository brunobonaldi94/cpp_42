/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:45:33 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/02 12:36:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"

class ICharacter;
class AMateria
{
	public:
		AMateria(std::string const & type);
		std::string const & getType() const; //Returns the materia type
		virtual ~AMateria();
		AMateria(AMateria const &src);
		AMateria &operator=(AMateria const &rhs);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string type;
};

#endif
