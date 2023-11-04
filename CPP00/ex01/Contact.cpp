/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:36:53 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 21:12:03 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//========= CONSTRUCTOR =========//

Contact::Contact( void ) { }

//========= DESTRUCTOR =========//

Contact::~Contact( void ) { }

//========= GETTER FUNCTION =========//

static std::string	getValuePrint(std::string contactField, const char *infoField)
{
	std::cout << infoField << ": ";
	return contactField;
}

std::string	Contact::getValue( int field, std::string (*print)(std::string, const char *), bool printFlag ) const
{
	if (field == 0)
		return printFlag == true ? print(_firstName, "First Name") : _firstName;
	else if (field == 1)
		return printFlag == true ? print(_lastName, "Last Name") : _lastName;
	else if (field == 2)
		return printFlag == true ? print(_nickname, "Nickname") : _nickname;
	else if (field == 3)
		return printFlag == true ? print(_phoneNumber, "Phone number") : _phoneNumber;
	else if (field == 4)
		return printFlag == true ? print(_darkestSecret, "Darkest secret") : _darkestSecret;
	return "";
}

//========= SETTER FUNCTION =========//

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

//========= INPUT HANDLER FUNCTION =========//

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

bool	checkInput( std::string input, int (*funct)(int) )
{
	size_t	len = input.length();

	if (funct && len > 0)
	{
		for (size_t i = 0; i < len; i++)
		{
			if (!funct(input[i]))
				return false;
		}
	}
	return true;
}

//========= MEMBER FUNCTION =========//

void	Contact::printInfo( int contactIndex )
{
	std::string	info;

	std::cout << std::setw(10) << std::right << (contactIndex + 1) << " | ";
	for (int i = 0; i < 3; i++)
	{
		info.assign(getValue(i, getValuePrint, false));
		if (info.length() > 10)
		{
			info.assign(info.substr(0, 9));
			info.append(".");
		}
		std::cout << std::setw(10) << std::right << info << " | ";
	}
	std::cout << std::endl;
}

void	Contact::indexPrint( void )
{
	for (int i = 0; i < 5; i++)
		std::cout << getValue(i, getValuePrint, true) << std::endl;
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
