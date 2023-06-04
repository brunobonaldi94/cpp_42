/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:28:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/06/04 00:04:28 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	Point p1(0,0);
	Point p2(20, 0);
	Point p3(10, 30);

	Point p4(10, 15);

	bool isInside = bsp(p1, p2, p3, p4);
	if (isInside)
		std::cout << "point is inside triangle";
	else
		std::cout << "point is not inside triangle";
	return 0;
}
