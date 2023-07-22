/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:10:38 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/22 00:23:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(long int n) : _N(n)
{
	if (n > std::numeric_limits<unsigned int>::max())
		throw std::length_error("Span: n is too big");
	debug("Span constructor called", GREEN);
}

Span::Span(Span const &src)
{
	debug("Span copy constructor called", GREEN);
	*this = src;
}

Span::~Span(void)
{
	debug("Span destructor called", GREEN);
}

Span &Span::operator=(Span const &rhs)
{
	debug("Span assignation operator called", GREEN);
	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_set = rhs._set;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (!this->canAdd())
		throw std::length_error("Span: no space left");
	this->_set.insert(n);
}

bool Span::canAdd()
{
	if (this->_set.size() > this->_N)
		return (false);
	return (true);
}

template <typename Iterator>
void Span::addRange(Iterator iterator)
{
	typename Iterator::const_iterator it;
	it = iterator;
	if (!this->canAdd())
		throw std::length_error("Span: no space left");
	this->_set.insert(it.begin(),	it.end());
}

unsigned int Span::longestSpan(void)
{
	if (this->_set.size() < 2)
		throw std::length_error("Span: no space left");
	return (*this->_set.rbegin() - *this->_set.begin());
}

unsigned int Span::shortestSpan(void)
{
	if (this->_set.size() < 2)
		throw std::length_error("Span: no space left");
	long int min = std::numeric_limits<long int>::max();
	std::set<int>::iterator it = this->_set.begin();
	std::set<int>::iterator it2 = ++this->_set.begin();
	std::set<int>::iterator end = --this->_set.end();
	--end;
	while(it != end)
	{
		if (*it2 - *it < min)
			min = *it2 - *it;
		if (min == 1)
			break ;
		it++;
		it2++;
	}
	return (min);
}

