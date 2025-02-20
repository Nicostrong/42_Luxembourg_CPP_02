/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:34 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/20 10:38:25 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:

		Fixed const	_x;
		Fixed const	_y;

	public:

		/*	Canonical Form	*/
		Point( void );
		Point( const float x, const float y );
		Point( const Point &src );
		~Point( void );

		Point		&operator=( const Point &src_object );

		/*	Getter	*/
		const Fixed	&getX( void ) const;
		const Fixed	&getY( void ) const;
};

bool			bsp( Point const a, Point const b, Point const c, Point const point );

std::ostream	&operator<<( std::ostream &out, const Point &src_object );

#endif
