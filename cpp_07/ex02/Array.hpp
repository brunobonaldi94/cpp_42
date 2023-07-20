/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:24:24 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/20 19:23:23 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include "colors.hpp"
# include "defines.hpp"
# include <time.h>
# include <stdlib.h>
#include <limits>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		~Array();
		Array &operator=(const Array &rhs);
		T &operator[](long int index);
	    const T& operator[](long int index) const; // Add const version
		unsigned int size() const;
		bool isEmpty() const;
		class OutOfBoundsException : public std::exception
		{
			public:
				OutOfBoundsException(long int index, unsigned int n);
				virtual const char* what() const throw();
			private:
				long int _index;
				unsigned int _n;
		};

	private:
		unsigned int	_n;
		T				*_array;
};

void debug(std::string param, std::string color);
template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> const &src);

#include "Array.tpp"
#endif

