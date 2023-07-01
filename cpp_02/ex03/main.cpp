/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:28:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/01 14:10:05 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	static const int size = 5;
	Point v1(0,0);
	Point v2(20, 0);
	Point v3(10, 30);

	Point point1(10, 15); //inside
	Point point2(5, 5); // inside
	Point point3(100, 150); // outside
	Point point4(20, 0); // vertex, thus outise
	Point point5(10, 0); // edge, thus outise
	Point points[size] = { point1, point2, point3, point4, point5 };

	for (int i = 0; i < size; i++)
		std::cout << (bsp(v1, v2, v3, points[i]) ? "True" : "False") << std::endl;
	return 0; 
}
