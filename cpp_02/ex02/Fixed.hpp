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
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(int const n);
		Fixed(float const f );
		Fixed(Fixed const & src);
		~Fixed();

		Fixed & operator=(Fixed const & rhs);
		bool	operator>(Fixed const & rhs);
		bool	operator<(Fixed const & rhs);
		bool	operator>=(Fixed const & rhs);
		bool	operator<=(Fixed const & rhs);
		bool	operator==(Fixed const & rhs);
		bool	operator!=(Fixed const & rhs);

		Fixed	operator+(Fixed const & rhs);
		Fixed	operator-(Fixed const & rhs);
		Fixed	operator*(Fixed const & rhs);
		Fixed	operator/(Fixed const & rhs);

		Fixed & operator++( void );
		Fixed & operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed const& min(Fixed const& a, Fixed const& b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed const& max(Fixed const& a, Fixed const& b);
		static Fixed &max(Fixed &a, Fixed &b);

	private:
		int _fixedPoint;
		static const int _fractionalBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif
