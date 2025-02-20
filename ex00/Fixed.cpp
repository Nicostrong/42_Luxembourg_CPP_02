/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:36:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/20 10:23:05 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*******************************************************************************
 *							CANONICAL FORM									   *
 ******************************************************************************/

/*
 *	Default constructor of class Fixed
 */
Fixed::Fixed( void ) : _fixedPointValue(0)
{
	std::cout << "Default constructor called." << std::endl;
	return ;
}

/*
 *	Copy constructor of class Fixed
 */
Fixed::Fixed( const Fixed &src )
{
	*this = src;
	std::cout << "Copy constructor called." << std::endl;
	return ;
}

/*
 *	Destructor of class Fixed
 */
Fixed::~Fixed( void )
{
	std::cout << "Destructor called." << std::endl;
	return ;
}

/*
 *	Assignation operator overload
 */
Fixed	&Fixed::operator=( const Fixed &src_object )
{
	std::cout << "Copy assignation operator called." << std::endl;
	if (this != &src_object)
		this->_fixedPointValue = src_object.getRawBits();
	return (*this);
}

/*******************************************************************************
 *								SETTER										   *
 ******************************************************************************/

/*
 *	Set the value of the fixed point
 */
void	Fixed::setRawBits( int const raw )
{
	this->_fixedPointValue = raw;
	return ;
}

/*******************************************************************************
 *								GETTER										   *
 ******************************************************************************/

/*
 *	Return the value of the fixed point
 */
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}
