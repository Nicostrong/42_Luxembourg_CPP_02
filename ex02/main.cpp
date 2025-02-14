/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:34:17 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/14 13:54:40 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed (2 ) );
	Fixed 		c;

	/*	show a and b	*/
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "a raw: " << a.getRawBits() << std::endl;
	std::cout << "b raw: " << b.getRawBits() << std::endl;
	std::cout << "c raw: " << c.getRawBits() << std::endl;

	/*	increment a	*/
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;

	/*	decrement a	*/
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;

	/*	show new a and b and c*/
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	/*	arithmetic	*/
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "b / c = " << b / c << std::endl;

	/*	show new a and b and c*/
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	/*	comparaison	*/
	std::cout << "a > b = " << (a > b) << std::endl;
	std::cout << "a < b = " << (a < b) << std::endl;
	std::cout << "a >= b = " << (a >= b) << std::endl;
	std::cout << "a <= b = " << (a <= b) << std::endl;
	std::cout << "a == b = " << (a == b) << std::endl;
	std::cout << "a != b = " << (a != b) << std::endl;
	std::cout << "a == c = " << (a == c) << std::endl;
	std::cout << "a != c = " << (a != c) << std::endl;

	/*	show new a and b*/
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << "max(a, b) = " << Fixed::max( a, b ) << std::endl;
  	std::cout << "min(a, b) = " << Fixed::min( a, b ) << std::endl;

	return (0);
}
