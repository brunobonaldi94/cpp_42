/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:36:36 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/24 13:09:10 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const & rhs);
		void learnMateria(AMateria * materia);
		AMateria* createMateria(std::string const & type);
	private:
		static const int MAX_SIZE = 4; 
		int materia_count;
		AMateria* materia[MAX_SIZE];
};

#endif

