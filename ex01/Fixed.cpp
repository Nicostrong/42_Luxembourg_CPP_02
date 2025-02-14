/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:36:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/14 11:42:52 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
 *	Default constructor of class Fixed
 */
Fixed::Fixed( void ) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

/*
 *	Copy constructor of class Fixed, copy the value of src to the current object
 */
Fixed::Fixed( const Fixed &src )
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

/*
 *	Constructor of class Fixed, convert the int value to fixed point value
 */
Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << Fixed::_fractionalBits;
	return ;
}

/*
 *	Constructor of class Fixed, convert the float value to fixed point value
 */
Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << Fixed::_fractionalBits));
	return ;
}

/*
 *	Destructor of class Fixed
 */
Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/*
 *	Assignation operator overload, assign the value of src_object to the current
 *	object
 */
Fixed	&Fixed::operator=( const Fixed &src_object )
{
	std::cout << "Copy assignation operator called" << std::endl;
	if (this != &src_object)
		this->_fixedPointValue = src_object.getRawBits();
	return (*this);
}

/*
 *	print the value of the fixed point like a float value on the stream out
 */
std::ostream	&operator<<( std::ostream &out, const Fixed &src_object )
{
	out << src_object.toFloat();
	return (out);
}

/*
 *	return the value of the fixed point as an float
 */
float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPointValue / (1 << Fixed::_fractionalBits));
}

/*
 *	return the value of the fixed point as an integer
 */
int		Fixed::toInt( void ) const
{
	return (this->_fixedPointValue >> Fixed::_fractionalBits);
}

/*
 *	Return the value of the fixed point
 */
int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

/*
 *	Set the value of the fixed point
 */
void	Fixed::setRawBits( int const raw )
{
	this->_fixedPointValue = raw;
	return ;
}
