/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:43:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/04 00:04:27 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float absolute_number(float f)
{
	if (f < 0)
		return f * -1.0;
	return f;
}

float	calculate_triangle_area(Point const & p1, Point const & p2, Point const & p3)
{
	
	return absolute_number(
		(p1.getXFloat() *(p2.getYFloat() - p3.getYFloat())
		+ p2.getXFloat()*(p3.getYFloat()-p1.getYFloat())
		+ p3.getXFloat()*(p1.getYFloat()- p2.getYFloat())) / 2.0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	float triangleArea_abc = calculate_triangle_area(a, b, c);
	float triangleArea_pbc = calculate_triangle_area(point, b, c);
	float triangleArea_pac = calculate_triangle_area(a, point, c);
	float triangleArea_pab = calculate_triangle_area(a, b, point);
	return (triangleArea_abc == (triangleArea_pab + triangleArea_pac + triangleArea_pbc));
}
