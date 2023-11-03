/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:12:14 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/03 14:46:46 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//========= CONSTRUCTOR =========//

Fixed::Fixed( void ) : _fixedNumber(0) { }

Fixed::Fixed( Fixed const & newInstance ) { *this = newInstance; }

Fixed::Fixed( int const intNumber ) : _fixedNumber(intNumber << this->_fractionalBits) { }

Fixed::Fixed( float const floatNumber ) : _fixedNumber(roundf(floatNumber * (1 << this->_fractionalBits))) { }

//========= DESTRUCTOR =========//

Fixed::~Fixed( void ) { }

//========= GETTER FUNCTION =========//

int	Fixed::getRawBits( void ) const { return this->_fixedNumber; }

//========= SETTER FUNCTION =========//

void	Fixed::setRawBits( int const raw ) { this->_fixedNumber = raw; }

//========= FROM-TO FUNCTIONS =========//

float Fixed::toFloat( void ) const { return (float)(this->_fixedNumber) / (float)(1 << this->_fractionalBits); }

int	Fixed::toInt( void ) const { return this->_fixedNumber >> this->_fractionalBits; }

//========= OPERATOR OUTPUT STREAM OVERLOAD =========//

std::ostream&	operator<<( std::ostream & stdOutStream, Fixed const & instance)
{
	stdOutStream << instance.toFloat();
	return stdOutStream;
}

//========= OPERATOR COMPARISON OVERLOAD =========//

Fixed&	Fixed::operator=( Fixed const & modifiedInstance )
{
	if (this != &modifiedInstance)
		this->_fixedNumber = modifiedInstance.getRawBits();
	return *this;
}

bool	Fixed::operator>( Fixed const & otherInstance ) const
{
	return this->_fixedNumber > otherInstance.getRawBits();
}

bool	Fixed::operator<( Fixed const & otherInstance ) const
{
	return this->_fixedNumber < otherInstance.getRawBits();
}

bool	Fixed::operator>=( Fixed const & otherInstance ) const
{
	return this->_fixedNumber >= otherInstance.getRawBits();
}

bool	Fixed::operator<=( Fixed const & otherInstance ) const
{
	return this->_fixedNumber <= otherInstance.getRawBits();
}

bool	Fixed::operator==( Fixed const & otherInstance ) const
{
	return this->_fixedNumber == otherInstance.getRawBits();
}

bool	Fixed::operator!=( Fixed const & otherInstance ) const
{
	return this->_fixedNumber != otherInstance.getRawBits();
}

//========= OPERATOR ARITHMETIC OVERLOAD =========//

Fixed	Fixed::operator+( Fixed const & otherInstance ) const
{
	return Fixed(this->toFloat() + otherInstance.toFloat());
}

Fixed	Fixed::operator-( Fixed const & otherInstance ) const
{
	return Fixed(this->toFloat() - otherInstance.toFloat());
}

Fixed	Fixed::operator*( Fixed const & otherInstance ) const
{
	return Fixed(this->toFloat() * otherInstance.toFloat());
}

Fixed	Fixed::operator/( Fixed const & otherInstance ) const
{
	return Fixed(this->toFloat() / otherInstance.toFloat());
}

//========= OPERATOR INCREMENT/DECREMENT OVERLOAD =========//

Fixed	Fixed::operator++( int )
{
	float	currentNumber;

	currentNumber = this->toFloat();
	this->_fixedNumber++;
	return Fixed(currentNumber);
}

Fixed	Fixed::operator--( int )
{
	float	currentNumber;

	currentNumber = this->toFloat();
	this->_fixedNumber--;
	return Fixed(currentNumber);
}

Fixed&	Fixed::operator++( void )
{
	++this->_fixedNumber;
	return *this;
}

Fixed&	Fixed::operator--( void )
{
	--this->_fixedNumber;
	return *this;
}

//========= STATIC MEMBER FUNCTIONS =========//

Fixed&	Fixed::min( Fixed& firstInstance, Fixed& secondInstance )
{
	return firstInstance.getRawBits() < secondInstance.getRawBits() ? firstInstance : secondInstance;
}

Fixed const &	Fixed::min( Fixed const & firstInstance, Fixed const & secondInstance )
{
	return firstInstance.getRawBits() < secondInstance.getRawBits() ? firstInstance : secondInstance;
}

Fixed&	Fixed::max( Fixed& firstInstance, Fixed& secondInstance )
{
	return firstInstance.getRawBits() > secondInstance.getRawBits() ? firstInstance : secondInstance;
}

Fixed const &	Fixed::max( Fixed const & firstInstance, Fixed const & secondInstance )
{
	return firstInstance.getRawBits() > secondInstance.getRawBits() ? firstInstance : secondInstance;
}
