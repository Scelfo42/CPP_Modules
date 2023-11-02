/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:06:13 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/02 17:04:51 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedNumber(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed( Fixed const & newInstance )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = newInstance;
}

Fixed::Fixed( int const intNumber )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedNumber = intNumber << this->_fractionalBits;
}

Fixed::Fixed( float const floatNumber )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedNumber = roundf(floatNumber * (1 << this->_fractionalBits));
}

Fixed::~Fixed( void ) { std::cout << "Destructor called" << std::endl; }

Fixed&	Fixed::operator=( Fixed const & modifiedInstance )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &modifiedInstance) // how to handle self-assignment
		return *this;
	this->_fixedNumber = modifiedInstance.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const { return this->_fixedNumber; }

void	Fixed::setRawBits( int const raw ) { this->_fixedNumber = raw; }

float Fixed::toFloat( void ) const { return (static_cast<float>(this->_fixedNumber) / (1 << this->_fractionalBits)); }

int	Fixed::toInt( void ) const { return this->_fixedNumber >> this->_fractionalBits; }

std::ostream&	operator<<( std::ostream & stdOutStream, Fixed const & instance)
{
	stdOutStream << instance.toFloat();
	return stdOutStream;
}

/*
Fixed::Fixed( void ) : _fixedNumber(0): This is the default constructor for the Fixed class. It initializes _fixedNumber to 0.

Fixed::Fixed( Fixed const & newInstance ): This is the copy constructor for the Fixed class. It's used when a new object is created as a copy of an existing object. The existing object is passed as a reference to the constructor.

Fixed::Fixed( int const intNumber ): This is a constructor that takes an integer as an argument. It shifts the integer to the left by _fractionalBits places and stores the result in _fixedNumber. This is a way of converting an integer to a fixed-point number.

Fixed::Fixed( float const floatNumber ): This is a constructor that takes a floating-point number as an argument. It multiplies the floating-point number by 1 << _fractionalBits (which is equivalent to 2 to the power of _fractionalBits), rounds to the nearest integer, and stores the result in _fixedNumber. This is a way of converting a floating-point number to a fixed-point number.

Fixed::~Fixed( void ): This is the destructor for the Fixed class. It's called when an object of the class is destroyed.

Fixed& Fixed::operator=( Fixed const & modifiedInstance ): This is the copy assignment operator for the Fixed class. It's used when an existing object is assigned the value of another existing object. The other object is passed as a reference to the operator. If the other object is the same as the current object (i.e., self-assignment), the operator returns a reference to the current object. Otherwise, it copies the value of _fixedNumber from the other object to the current object and returns a reference to the current object.

int Fixed::getRawBits( void ) const: This is a getter function that returns the value of _fixedNumber.

void Fixed::setRawBits( int const raw ): This is a setter function that sets the value of _fixedNumber.

float Fixed::toFloat( void ) const: This function converts the fixed-point number stored in _fixedNumber to a floating-point number. It does this by dividing _fixedNumber by 1 << _fractionalBits (which is equivalent to 2 to the power of _fractionalBits) and rounding to the nearest integer.

int Fixed::toInt( void ) const: This function converts the fixed-point number stored in _fixedNumber to an integer. It does this by shifting _fixedNumber to the right by _fractionalBits places.

std::ostream& operator<<( std::ostream & stdOutStream, Fixed const & instance): This is an overload of the << operator for the Fixed class. It's used to output an object of the Fixed class to an output stream. It outputs the floating-point representation of the object.
*/