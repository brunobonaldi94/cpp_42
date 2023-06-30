/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:28:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/29 23:15:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	checkPointInsideTriangle( Point const a, Point const b, Point const c, Point const point )
{
	bool isInside = bsp(a, b, c, point);
	if (isInside)
		std::cout << "is";
	else
		std::cout << "is not";
	std::cout << " inside triangle" << std::endl;
	return isInside;
}

int main( void )
{
	static const int size = 4;
	Point p1(0,0);
	Point p2(20, 0);
	Point p3(10, 30);


	Point point1(10, 15);
	Point point2(5, 5);
	Point point3(100, 150);
	Point point4(20, 0);
	Point points[size] = {point1, point2, point3, point4};

	for (int i = 0; i < size; i++) {
		std::cout << "point" << i + 1 << "(x=" << points[i].getXFloat() << ",y=" << points[i].getYFloat() << ") ";
		checkPointInsideTriangle(p1, p2, p3, points[i]);
	}
	return 0;
}
