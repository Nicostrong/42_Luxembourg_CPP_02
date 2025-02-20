/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:36:19 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/20 10:35:55 by nfordoxc         ###   Luxembourg.lu     */
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
	//	std::cout << "Default constructor called." << std::endl;
	return ;
}

/*
 *	Copy constructor of class Fixed
 */
Fixed::Fixed( const Fixed &src )
{
	*this = src;
	//	std::cout << "Copy constructor called." << std::endl;
	return ;
}

/*
 *	Constructor of class Fixed, convert the int value to fixed point value
 */
Fixed::Fixed( const int value )
{
	//	std::cout << "Int constructor called." << std::endl;
	this->_fixedPointValue = value << Fixed::_fractionalBits;
	return ;
}

/*
 *	Constructor of class Fixed, convert the float value to fixed point value
 */
Fixed::Fixed( const float value )
{
	//	std::cout << "Float constructor called." << std::endl;
	this->_fixedPointValue = roundf(value * (1 << Fixed::_fractionalBits));
	return ;
}

/*
 *	Destructor of class Fixed
 */
Fixed::~Fixed( void )
{
	//	std::cout << "Destructor called." << std::endl;
	return ;
}

/*
 *	Assignation operator overload
 */
Fixed	&Fixed::operator=( const Fixed &src_object )
{
	//	std::cout << "Copy assignation operator called" << std::endl;
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
	//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

/*******************************************************************************
 *								METHOD 										   *
 ******************************************************************************/

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

/*******************************************************************************
 *							COMPARATOR OPERATOR								   *
 ******************************************************************************/

/*
 *	Comparison operator overload bigger than
 */
bool	Fixed::operator>( const Fixed &src_object ) const
{
	return (this->_fixedPointValue > src_object.getRawBits());
}

/*
 *	Comparison operator overload less than
 */
bool	Fixed::operator<( const Fixed &src_object ) const
{
	return (this->_fixedPointValue < src_object.getRawBits());
}

/*
 *	Comparison operator overload bigger or equal than
 */
bool	Fixed::operator>=( const Fixed &src_object ) const
{
	return (this->_fixedPointValue >= src_object.getRawBits());
}

/*
 *	Comparison operator overload less or equal than
 */
bool	Fixed::operator<=( const Fixed &src_object ) const
{
	return (this->_fixedPointValue <= src_object.getRawBits());
}

/*
 *	Comparison operator overload equal than
 */
bool	Fixed::operator==( const Fixed &src_object ) const
{
	return (this->_fixedPointValue == src_object.getRawBits());
}

/*
 *	Comparison operator overload different than
 */
bool	Fixed::operator!=( const Fixed &src_object ) const
{
	return (this->_fixedPointValue != src_object.getRawBits());
}

/*******************************************************************************
 *							ARITHMETIC OPERATOR								   *
 ******************************************************************************/

/*
 *	Arithmetic operator overload addition
 */
Fixed	Fixed::operator+( const Fixed &src_object ) const
{
	Fixed	result;

	result.setRawBits(this->_fixedPointValue + src_object.getRawBits());
	return (result);
}

/*
 *	Arithmetic operator overload subtraction
 */
Fixed	Fixed::operator-( const Fixed &src_object ) const
{
	Fixed	result;

	result.setRawBits(this->_fixedPointValue - src_object.getRawBits());
	return (result);
}

/*
 *	Arithmetic operator overload multiplication
 */
Fixed	Fixed::operator*( const Fixed &src_object ) const
{
	Fixed	result;

	result.setRawBits((this->_fixedPointValue * src_object.getRawBits()) >> Fixed::_fractionalBits);
	return (result);
}

/*
 *	Arithmetic operator overload division
 */
Fixed	Fixed::operator/( const Fixed &src_object ) const
{
	Fixed	result;

	if (src_object.getRawBits() == 0)
	{
		std::cout << "Error: division by zero" << std::endl;
		return (Fixed());
	}
	result.setRawBits((this->_fixedPointValue << this->_fractionalBits) / src_object.getRawBits());
	return (result);
}

/*******************************************************************************
 *							INCREMENT / DECREMENT							   *
 ******************************************************************************/

/*
 *	Increment operator overload pre-increment
 */
Fixed	&Fixed::operator++( void )
{
	this->_fixedPointValue++;
	return (*this);
}

/*
 *	Increment operator overload post-increment
 */
Fixed	Fixed::operator++( int )
{
	Fixed	tmp(*this);

	this->_fixedPointValue++;
	return (tmp);
}

/*
 *	Decrement operator overload pre-decrement
 */
Fixed	&Fixed::operator--( void )
{
	this->_fixedPointValue--;
	return (*this);
}

/*
 *	Decrement operator overload post-decrement
 */
Fixed	Fixed::operator--( int )
{
	Fixed	tmp(*this);

	this->_fixedPointValue--;
	return (tmp);
}

/*******************************************************************************
 *								MIN / MAX									   *
 ******************************************************************************/

/*
 *	Return the minimum value between a and b
 */
Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	return (a < b ? a : b);
}

/*
 *	Return the maximum value between a and b
 */
Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	return (a > b ? a : b);
}

/*
 *	Return the minimum value between a and b
 */
const Fixed	&Fixed::min( const Fixed &a, const Fixed &b )
{
	return (a < b ? a : b);
}

/*
 *	Return the maximum value between a and b
 */
const Fixed	&Fixed::max( const Fixed &a, const Fixed &b )
{
	return (a > b ? a : b);
}

/*******************************************************************************
 *							OUTSTREAM OPERATOR								   *
 ******************************************************************************/

/*
 *	print the value of the fixed point like a float value on the stream out
 */
std::ostream	&operator<<( std::ostream &out, const Fixed &src_object )
{
	out << src_object.toFloat();
	return (out);
}
