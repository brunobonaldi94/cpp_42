/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:43:50 by bbonaldi          #+#    #+#             */
/*   Updated: 2023/07/01 14:08:19 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float absolute_number(float f)
{
	if (f < 0)
		return f * -1.0;
	return f;
}

void	print_point(Point const &p, std::string name)
{
	std::cout << name << " (x=" << p.getXFloat() << ",y=" << p.getYFloat() << ") ";
}

bool printResult(Point const &p, Point *vertex, bool result, std::string message = "")
{
	print_point(p, "point");
	if (result)
		std::cout << "is";
	else
		std::cout << "is not";
	std::cout << " inside triangle ";
	print_point(vertex[0], "v1");
	print_point(vertex[1], "v2");
	print_point(vertex[2], "v3");
	std::cout << message << std::endl;
	return result;
}

bool isOnVertex( Point const v, Point const point )
{
	return (v.getYFloat() == point.getYFloat() && v.getXFloat() == point.getXFloat());
}

bool isOnEdge(const Point& p, const Point& v1, const Point& v2)
{
    float a = v1.getYFloat() - v2.getYFloat();
    float b = v2.getXFloat() - v1.getXFloat();
    float c = v1.getXFloat() * v2.getYFloat()- v2.getXFloat() * v1.getYFloat();
    float result = a * p.getXFloat() + b * p.getYFloat() + c;
    float tolerance = 1e-6; 
    return (result < tolerance && result > -tolerance);
}

bool checkIsNotEdgeOrVertex(Point *vertex, Point const point)
{
	for (int i = 0; i < 3; i++)
	{
		if (isOnVertex(vertex[i], point))
			return printResult(point, vertex, false, "because is on vertex");
	}
	for (int i = 0; i < 3; i++)
	{
		int j = i == 2 ? 0 : i + 1;
		if (isOnEdge(point, vertex[i], vertex[j]))
			return printResult(point, vertex, false, "because is on edge");
	}
	return true;
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
	Point vertex[3] = { a, b, c };
	bool isInside = false;

	if (!checkIsNotEdgeOrVertex(vertex, point))
		return isInside;
	float triangleArea_abc = calculate_triangle_area(a, b, c);
	float triangleArea_pbc = calculate_triangle_area(point, b, c);
	float triangleArea_pac = calculate_triangle_area(a, point, c);
	float triangleArea_pab = calculate_triangle_area(a, b, point);
	isInside = triangleArea_abc == (triangleArea_pab + triangleArea_pac + triangleArea_pbc);
	return printResult(point, vertex, isInside);
}
