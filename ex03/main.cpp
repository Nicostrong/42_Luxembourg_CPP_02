/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:34:17 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/14 14:49:38 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main( void )
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	Point p1(5.0f, 5.0f);  // Inside
	Point p2(0.0f, 0.0f);  // On vertex a
	Point p3(5.0f, 0.0f);  // On line ab
	Point p4(15.0f, 5.0f); // Outside

	std::cout	<< "Point p1 is inside the triangle: "
				<< (bsp(a, b, c, p1) == 1 ? "YES" : "NO") << std::endl;
	std::cout	<< "Point p2 is inside the triangle: "
				<< (bsp(a, b, c, p2) == 1 ? "YES" : "NO") << std::endl;
	std::cout	<< "Point p3 is inside the triangle: "
				<< (bsp(a, b, c, p3) == 1 ? "YES" : "NO") << std::endl;
	std::cout	<< "Point p4 is inside the triangle: "
				<< (bsp(a, b, c, p4) == 1 ? "YES" : "NO") << std::endl;

	Point d(-10.0f, -5.0f);
	Point e(-5.0f, -10.0f);
	Point f(-7.5f, 0.0f);

	Point p5(-8.0f, -5.0f);
	Point p6(-2.8f, 0.6f);

	std::cout	<< "Point p5 is inside the triangle: "
				<< (bsp(d, e, f, p5) == 1 ? "YES" : "NO") << std::endl;
	std::cout	<< "Point p6 is inside the triangle: "
				<< (bsp(d, e, f, p6) == 1 ? "YES" : "NO") << std::endl;

	return (0);
}
