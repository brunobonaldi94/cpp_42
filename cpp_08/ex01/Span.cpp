/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:10:38 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/24 22:39:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(long int n) : _N(n)
{
	if (n > std::numeric_limits<unsigned int>::max())
		throw Span::NoSpaceException();
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
		this->_shortestSpans[0] = rhs._shortestSpans[0];
		this->_shortestSpans[1] = rhs._shortestSpans[1];
		this->_longestSpans[0] = rhs._longestSpans[0];
		this->_longestSpans[1] = rhs._longestSpans[1];
		this->_Multiset = rhs._Multiset;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (!this->canAdd())
		throw Span::NoSpaceException();
	this->_Multiset.insert(n);
}

bool Span::canAdd()
{
	if (this->_Multiset.size() >= this->_N)
		return (false);
	return (true);
}

unsigned int Span::longestSpan(void)
{
	if (this->_Multiset.size() < 2)
		throw Span::TooFewNumbersException();
	this->_longestSpans[0] = *this->_Multiset.begin();
	this->_longestSpans[1] = *this->_Multiset.rbegin();
	return (this->_longestSpans[1] - this->_longestSpans[0]);
}

unsigned int Span::shortestSpan(void)
{
	if (this->_Multiset.size() < 2)
		throw Span::TooFewNumbersException();
	long int min = std::numeric_limits<long int>::max();
	std::set<int>::iterator it = this->_Multiset.begin();
	std::set<int>::iterator it2 = ++this->_Multiset.begin();
	std::set<int>::iterator end = --this->_Multiset.end();
	--end;
	while(it != end)
	{
		if (*it2 - *it < min)
		{
			min = *it2 - *it;
			this->_shortestSpans[0] = *it;
			this->_shortestSpans[1] = *it2;
		}
		it++;
		it2++;
	}
	return (min);
}

void Span::printShortestSpan()
{
	std::cout << "Shortest Span is: " << this->shortestSpan() << " ( " << this->_shortestSpans[1] << " - " << this->_shortestSpans[0] << " ) " << std::endl;
}

void Span::printLongestSpan()
{
	std::cout << "Longest Span is: " << this->longestSpan() << " ( " << this->_longestSpans[1] << " - " << this->_longestSpans[0] << " ) " << std::endl;

}

unsigned int Span::getSize(void)
{
	return (this->_Multiset.size());
}

Span::TooFewNumbersException::TooFewNumbersException(void)
{
}

const char* Span::TooFewNumbersException::what() const throw()
{
	return ("Span: too few numbers");
}

Span::NoSpaceException::NoSpaceException(void)
{
}

const char* Span::NoSpaceException::what() const throw()
{
	return ("Span: no space left");
}
