/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:36:53 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/13 19:16:04 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void )
{
	std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact( void )
{
	std::cout << "Contact destructor called" << std::endl;
	return ;
}

std::string	Contact::getValue( std::string name )
{
	if (name.compare("First Name"))
		return this->_firstName;
	else if (name.compare("Last Name"))
		return this->_lastName;
	else if (name.compare("Nickname"))
		return this->_nickname;
	else if (name.compare("Phone Number"))
		return this->_phoneNumber;
	else if (name.compare("Darkest secret"))
		return this->_darkestSecret;
}

std::string Contact::setValue( std::string name, std::string value )
{
	if (name.compare("First Name"))
		this->_firstName = value;
	else if (name.compare("Last Name"))
		this->_lastName = value;
	else if (name.compare("Nickname"))
		this->_nickname = value;
	else if (name.compare("Phone Number"))
		this->_phoneNumber = value;
	else if (name.compare("Darkest secret"))
		this->_darkestSecret = value;
	else
		std::cerr << "Something unexpected happened in Contact::setValue()" << std::endl;
}

std::string Contact::checkValue( int field )
{
	std::string	input;

	while (1)
	{
		input.assign( setField( field ) );
		std::cout << 		
	}
}
