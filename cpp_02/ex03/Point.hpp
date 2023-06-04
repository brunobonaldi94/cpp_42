/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:21:03 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/03 23:56:50 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const &src);
		Point &operator=(Point const &rhs);
		~Point(void);

		void	setX(float const x);
		Fixed	getX( void ) const;
		void	setY(float const y);
		Fixed	getY( void ) const;
		void	setXY (Point const & point);
		float	getXFloat( void ) const;
		float	getYFloat( void ) const;
	private:
		Fixed const x;
		Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
