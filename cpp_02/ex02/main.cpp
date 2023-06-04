/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:28:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/04 00:09:29 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c;
	c = b;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "-- my tests--" << std::endl;
	std::cout << c << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << c + b << std::endl;
	std::cout << c - b  << std::endl;
	std::cout << c * b  << std::endl;
	std::cout << c / b  << std::endl;
	std::cout << c--  << std::endl;
	std::cout << --c  << std::endl;

	return 0;
}
