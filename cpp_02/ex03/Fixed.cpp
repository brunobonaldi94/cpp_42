/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:38:59 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/04 00:00:04 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixedPoint = 0;
}
Fixed::Fixed(const int n)
{
	this->_fixedPoint = n << this->_fractionalBits;
}

Fixed::Fixed(float const f )
{
	this->_fixedPoint = roundf(f * (1 << this->_fractionalBits));
	
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}
Fixed::~Fixed(){ }

Fixed & Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_fixedPoint = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->_fixedPoint;
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedPoint = raw;
}

int	Fixed::toInt( void ) const
{
	return this->_fixedPoint >> this->_fractionalBits;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_fixedPoint)) / (1 << this->_fractionalBits);
}

bool Fixed::operator>(Fixed const & rhs)
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const & rhs)
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const & rhs)
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs)
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const & rhs)
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs)
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const & rhs)
{
	return Fixed(this->toFloat() + rhs.toFloat());
}
Fixed Fixed::operator-(Fixed const & rhs)
{
	return Fixed(this->toFloat() - rhs.toFloat());
}
Fixed Fixed::operator*(Fixed const & rhs)
{
	return Fixed(this->toFloat() * rhs.toFloat());
}
Fixed Fixed::operator/(Fixed const & rhs)
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed & Fixed::operator++( void )
{
	this->_fixedPoint++;
	return *this;
}
Fixed &	Fixed::operator--( void )
{
	this->_fixedPoint--;
	return *this;
}

Fixed  Fixed::operator++( int )
{
	Fixed temp(*this);
	this->_fixedPoint++;
	return (temp);
}

Fixed  Fixed::operator--( int )
{
	Fixed temp(*this);
	this->_fixedPoint--;
	return (temp);
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}
Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return o;
}
