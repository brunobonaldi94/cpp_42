/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:29:01 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/02 19:20:11 by bbonaldi         ###   ########.fr       */
/*                                                                            */          
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
	public:
		Fixed();
		Fixed(int const n);
		Fixed(float const f );
		Fixed(Fixed const & src);
		~Fixed();

		Fixed & operator=(Fixed const & rhs);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int _fixedPoint;
		static const int _fractionalBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif
