/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:36:07 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/14 13:19:32 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:

		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:

		Fixed( void );
		Fixed( const Fixed &src );
		Fixed( const int value );
		Fixed( const float value );
		~Fixed( void );

		/*	Assignation	*/
		Fixed				&operator=( const Fixed &src_object );

		/*	Comparator	*/
		bool				operator>( const Fixed &src_object ) const;
		bool				operator<( const Fixed &src_object ) const;
		bool				operator>=( const Fixed &src_object ) const;
		bool				operator<=( const Fixed &src_object ) const;
		bool				operator==( const Fixed &src_object ) const;
		bool				operator!=( const Fixed &src_object ) const;

		/*	Arithmetic	*/
		Fixed				operator+( const Fixed &src_object ) const;
		Fixed				operator-( const Fixed &src_object ) const;
		Fixed				operator*( const Fixed &src_object ) const;
		Fixed				operator/( const Fixed &src_object ) const;

		/*	Increment / Decrement / post / pre	*/
		Fixed				&operator++( void );
		Fixed				&operator--( void );
		Fixed				operator++( int );
		Fixed				operator--( int );

		/*	max / min	*/
		static Fixed		&min( Fixed &a, Fixed &b );
		static Fixed		&max( Fixed &a, Fixed &b );
		static const Fixed	&min( const Fixed &a, const Fixed &b );
		static const Fixed	&max( const Fixed &a, const Fixed &b );

		/*	convert	*/
		float				toFloat( void ) const;
		int					toInt( void ) const;

		/*	getter / setter	*/
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );

};

std::ostream	&operator<<( std::ostream &out, const Fixed &src_object );

#endif
