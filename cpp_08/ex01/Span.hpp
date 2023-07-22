/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:52 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/22 00:01:25 by bbonaldi         ###   ########.fr       */
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

class Span
{
	public:
		Span(long int n);
		Span(Span const &src);
		~Span(void);
		Span &operator=(Span const &rhs);
		void addNumber(int n);
		template <typename Iterator>
		void addRange(Iterator it);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
	private:
		unsigned int _N;
		std::set<int> _set;
		bool canAdd();
};
void debug(std::string param, std::string color);
#endif
