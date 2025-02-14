/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:36:07 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/14 11:04:26 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:

		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:

		Fixed( void );
		Fixed( const Fixed &src );
		~Fixed( void );

		Fixed	&operator=( const Fixed &src_object );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};

#endif
