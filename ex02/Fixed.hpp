/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:36:07 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/20 10:33:28 by nfordoxc         ###   Luxembourg.lu     */
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

		/*	Canonical Form	*/
		Fixed( void );
		Fixed( const Fixed &src );
		Fixed( const int value );
		Fixed( const float value );
		~Fixed( void );

		Fixed				&operator=( const Fixed &src_object );

		/*	Setter	*/
		void				setRawBits( int const raw );

		/*	Getter	*/
		int					getRawBits( void ) const;

		/*	Method	*/
		float				toFloat( void ) const;
		int					toInt( void ) const;

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

};

std::ostream	&operator<<( std::ostream &out, const Fixed &src_object );

#endif
