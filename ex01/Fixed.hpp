/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:36:07 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/14 11:42:52 by nfordoxc         ###   Luxembourg.lu     */
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

		Fixed			&operator=( const Fixed &src_object );

		float			toFloat( void ) const;
		int				toInt( void ) const;

		int				getRawBits( void ) const;
		void			setRawBits( int const raw );

};

std::ostream	&operator<<( std::ostream &out, const Fixed &src_object );

#endif
