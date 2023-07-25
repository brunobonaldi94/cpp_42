/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:52 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/24 22:21:59 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <exception>
#include "colors.hpp"
#include "defines.hpp"
#include <limits>
#include <vector>
class Span
{
	public:
		Span(long int n);
		Span(Span const &src);
		~Span(void);
		Span &operator=(Span const &rhs);
		void addNumber(int n);
		template <typename Iterator>
		void addRange(Iterator it_begin, Iterator it_end);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		unsigned int getSize(void);

		void printShortestSpan(void);
		void printLongestSpan(void);

		class NoSpaceException : public std::exception
		{
			public:
				NoSpaceException();
				virtual const char* what() const throw();
		};

		class TooFewNumbersException : public std::exception
		{
			public:
				TooFewNumbersException();
				virtual const char* what() const throw();
		};
	
	private:
		unsigned int _N;
		std::multiset<int> _Multiset;
		int _shortestSpans[2];
		int _longestSpans[2];
		bool canAdd();

};
void debug(std::string param, std::string color);

# include "Span.tpp"

#endif
