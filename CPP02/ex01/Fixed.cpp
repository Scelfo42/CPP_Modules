/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:06:13 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/03 12:50:17 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

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

float Fixed::toFloat( void ) const 
{
	return (float)(this->_fixedNumber) / (float)(1 << this->_fractionalBits); 
}

int	Fixed::toInt( void ) const 
{
	return this->_fixedNumber >> this->_fractionalBits; 
}

std::ostream&	operator<<( std::ostream & stdOutStream, Fixed const & instance)
{
	stdOutStream << instance.toFloat();
	return stdOutStream;
}
