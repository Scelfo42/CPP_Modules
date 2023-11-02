/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:11:26 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/02 16:14:37 by cscelfo          ###   ########.fr       */
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

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=( Fixed const & modifiedInstance )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &modifiedInstance) // how to handle self-assignment
		return *this;
	this->_fixedNumber = modifiedInstance.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedNumber;
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedNumber = raw;
}
