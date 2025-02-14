/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:11 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/14 14:44:44 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
 *	Function to calculate the area of a triangle using the coordinates of its points
 */
static Fixed	area( Point const a, Point const b, Point const c )
{
	return (Fixed((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + \
					b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) + \
					c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2));
}

/*
 *	Binary Space Partitioning function
 *	Check if the point is inside the triangle a, b, c
 *	BSP Algorithme calculate the area of the original triangle and the area of 
 *	the three new triangles. If the sum of the three new triangles is equal to 
 *	the original triangle and the three new triangles are not null, the point is
 *	inside the triangle. If the point is on the edge of the triangle, her area 
 *	is equal to 0, we need to exclude this case.
 */
bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	A = area(a, b, c);
	Fixed	A1 = area(point, b, c);
	Fixed	A2 = area(a, point, c);
	Fixed	A3 = area(a, b, point);

	return (A == (A1 + A2 + A3) && A1 > 0 && A2 > 0 && A3 > 0);
}