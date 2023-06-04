/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:38:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/03 23:59:27 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0),y(0)
{

}

Point::Point(float const x, float const y)
{
	this->setX(x);
	this->setY(y);
}

Point::Point(Point const &src)
{
	*this = src;
}


Point & Point::operator=(Point const &rhs)
{
	if (this != &rhs)
		this->setXY(rhs);
	return *this;
}

Point::~Point(void){ }

void	Point::setX(float const x)
{
	const_cast<Fixed &>(this->x) = Fixed(x);
}
Fixed	Point::getX( void ) const
{
	return this->y;
}
void	Point::setY(float const y)
{
	const_cast<Fixed &>(this->y) = Fixed(y);
}
Fixed	Point::getY( void ) const
{
	return this->y;
}
void	Point::setXY (Point const & point)
{
	this->setX(point.getX().toFloat());
	this->setY(point.getY().toFloat());
}

float	Point::getXFloat( void ) const
{
	return this->x.toFloat();
}
float	Point::getYFloat( void ) const
{
	return this->y.toFloat();
}
