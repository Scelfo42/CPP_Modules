/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:06:13 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 20:42:38 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//========= CONSTRUCTOR =========//

Fixed::Fixed( void ) : _fixedNumber(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed( Fixed const & newInstance )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = newInstance;
}

Fixed::Fixed( int const intNumber ) : _fixedNumber(intNumber << _fractionalBits) { std::cout << "Int constructor called" << std::endl; }

Fixed::Fixed( float const floatNumber ) : _fixedNumber(roundf(floatNumber * (1 << _fractionalBits))) { std::cout << "Float constructor called" << std::endl; }

//========= DESTRUCTOR =========//

Fixed::~Fixed( void ) { std::cout << "Destructor called" << std::endl; }

//========= OPERATOR ASSIGNMENT OVERLOAD =========//

Fixed&	Fixed::operator=( Fixed const & modifiedInstance )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &modifiedInstance) // how to handle self-assignment
		return *this;
	this->_fixedNumber = modifiedInstance.getRawBits();
	return *this;
}

//========= GETTER FUNCTION =========//

int	Fixed::getRawBits( void ) const { return this->_fixedNumber; }

//========= SETTER FUNCTION =========//

void	Fixed::setRawBits( int const raw ) { this->_fixedNumber = raw; }

//========= FROM-TO FUNCTIONS =========//

float Fixed::toFloat( void ) const 
{
	return (float)(this->_fixedNumber) / (float)(1 << this->_fractionalBits); 
}

int	Fixed::toInt( void ) const 
{
	return this->_fixedNumber >> this->_fractionalBits; 
}

//========= OPERATOR OUTPUT STREAM OVERLOAD =========//

std::ostream&	operator<<( std::ostream & stdOutStream, Fixed const & instance)
{
	stdOutStream << instance.toFloat();
	return stdOutStream;
}
