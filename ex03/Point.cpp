/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:21 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/14 14:29:18 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
 *	Default constructor of class Point with 0 in value _x and _y
 */
Point::Point( void ) : _x(0), _y(0)
{
	return ;
}

/*
 *	Constructor with two float value in class Fixed
 */
Point::Point( const float x, const float y ) : _x(x), _y(y)
{
	return ;
}

/*
 *	Copy constructor from src value
 */
Point::Point( const Point &src ) : _x(src.getX()), _y(src.getY())
{
	return ;
}

/*
 *	Destructor of class Point
 */
Point::~Point( void )
{
	return ;
}

/*
 *	Get the value of point X
 */
const Fixed	&Point::getX( void ) const
{
	return (this->_x);
}

/*
 *	Get the value of point Y
 */
const Fixed	&Point::getY( void ) const
{
	return (this->_y);
}
