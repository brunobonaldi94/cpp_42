/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:36:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/24 13:53:52 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): materia_count(0)
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < this->MAX_SIZE; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < this->MAX_SIZE; i++)
		if (this->materia[i])
			delete this->materia[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const &rhs)
{
	std::cout << "MateriaSource Copy Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->materia_count = rhs.materia_count;
		for (int i = 0; i < this->MAX_SIZE; i++)
		{
			if (this->materia[i])
				delete this->materia[i];
			this->materia[i] = rhs.materia[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (this->materia_count >= this->MAX_SIZE)
		std::cout << "MateriaSource is full" << std::endl;
	this->materia[this->materia_count] = materia;
	this->materia_count++;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->MAX_SIZE; i++)
	{
		AMateria *materia = this->materia[i];
		if (materia && materia->getType() == type)
			return materia->clone();
	}
	return NULL;
}
