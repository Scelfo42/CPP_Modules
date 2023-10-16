/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:36:53 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/16 17:04:58 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void )
{
	return ;
}

Contact::~Contact( void )
{
	return ;
}

std::string	Contact::getValue( int field )
{
	if (field == 0)
		return this->_firstName;
	else if (field == 1)
		return this->_lastName;
	else if (field == 2)
		return this->_nickname;
	else if (field == 3)
		return this->_phoneNumber;
	else if (field == 4)
		return this->_darkestSecret;
	return "";
}

std::string Contact::setValue( int field , std::string value )
{
	if (field == 0)
		return (this->_firstName.assign( value ));
	else if (field == 1)
		return (this->_lastName.assign( value ));
	else if (field == 2)
		return (this->_nickname.assign( value ));
	else if (field == 3)
		return (this->_phoneNumber.assign( value ));
	else if (field == 4)
		return (this->_darkestSecret.assign( value ));
	return "";
}

static std::string chooseField( int field, int (**funct)(int) )
{
	if (field == 0 || field == 1)
	{
		*funct = std::isalpha;
		if (field == 0)
			return ("First name");
		return ("Last name");
	}
	else if (field == 2 || field == 4)
	{
		*funct = NULL;
		if (field == 2)
			return ("Nickname");
		return ("Darkest Secret");
	}
	*funct = std::isdigit;
	return ("Phone Number");
}

static bool	checkInput( std::string input, int (*funct)(int) )
{
	size_t	len = input.length();

	if (funct)
	{
		for (size_t i = 0; i < len; i++)
		{
			if (!funct(input[i]))
				return false;
		}
	}
	return true;
}

std::string	Contact::checkValue( int field )
{
	std::string	input;
	int			(*funct)(int);

	while (1)
	{
		std::cout << "Enter " << chooseField( field, &funct ) << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		else if (!input.compare(""))
			std::cerr << "Contact fields can't be empty" << std::endl;
		else if (checkInput( input, funct ) )
			return setValue( field, input );
		else
			std::cerr << "Input is incorrect" << std::endl;
	}
	return "";
}
