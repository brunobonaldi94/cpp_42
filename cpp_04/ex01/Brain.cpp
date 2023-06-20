/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:35:22 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/19 23:14:34 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string castIntToString(int number)
{
	std::stringstream ss;
	ss << number;
	std::string str = ss.str();
	return str;
}

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < this->MAX_IDEAS; i++)
		this->ideas[i] = "Default idea " + castIntToString(i);
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->setIdeas(rhs.getIdeas());
	return *this;
}

std::string* Brain::getIdeas( void ) const
{
	return const_cast<std::string*>(this->ideas);
}

void Brain::setIdeas(std::string const *ideas)
{
	for (int i = 0; i < this->MAX_IDEAS; i++)
		this->ideas[i] = ideas[i];
}

std::string Brain::getIdeaByIndex(int index) const
{
	if (index < 0 || index >= 100)
		return "";
	return this->ideas[index];
}

void Brain::setIdeaByIndex(int index, std::string idea)
{
	if (index < 0 || index >= 100)
		return ;
	this->ideas[index] = idea;
}
