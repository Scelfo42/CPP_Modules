/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:35:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/17 18:02:04 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	this->_countContacts = 0;
	this->_replaceOldest = 0;
	return ;
}

PhoneBook::~PhoneBook( void )
{
	return ;
}

void	PhoneBook::addContact( bool* ctrlD )
{
	if (this->_countContacts < 8)
	{
		for (int field = 0; field < 5; field++)
		{
			if (!this->_contacts[this->_countContacts].checkValue(field).compare(""))
			{
				*ctrlD = true;
				break ;
			}
		}
		this->_countContacts++;
	}
	else
	{
		for (int field = 0; field < 5; field++)
		{
			if (!this->_contacts[this->_replaceOldest].checkValue(field).compare(""))
			{
				*ctrlD = true;
				break ;
			}
		}
		this->_replaceOldest++;
		if (this->_replaceOldest == this->_countContacts)
			this->_replaceOldest = 0;
	}
}

void	PhoneBook::indexPrint( int index )
{
	if (index > 8 || this->_countContacts < index)
		std::cerr << "No contact found at this index" << std::endl;
	else
	{
		std::cout << index << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << this->_contacts[index - 1].getValue(i) << std::endl;
	}
}

void	PhoneBook::searchContact( bool* ctrlD )
{
	std::string	contact_info;
	std::string line;
	std::string input;
	size_t		len;
	
	if (this->_countContacts == 0)
	{
		std::cout << std::endl << "There isn't any contact saved" << std::endl;
		return ;
	}
	for (int i = 0; i < this->_countContacts; i++)
	{
		std::cout << "         " << (i + 1) << " | ";
		for (int j = 0; j < 3; j++)
		{
			line.assign("          ");
			contact_info = this->_contacts[i].getValue(j);
			len = contact_info.length();
			if (len > 10)
				len = 10;
			line.replace(10 - len, len, contact_info);
			if (contact_info.length() > 10)
			{
				line.replace(10, 10, ".");
				line.resize(11);
			}
			std::cout << line;
			if (j != 2 && line.find('.', 10) != 10)
				std::cout << " ";
			if (j != 2)
				std::cout << "| ";
		}
		std::cout << std::endl;
	}
	while (!std::cin.eof())
	{
		std::cout << std::endl << "Select a contact index to visualize all information about it: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			continue ;
		else if (!input.compare("no"))
		{
			std::cout << "Ok!" << std::endl;
			return ;
		}
		else if (input.compare("") && checkInput( input, std::isdigit ))
		{
			indexPrint( atoi( input.c_str() ) );
			return ;
		}
		else
			std::cerr << "Index must be numeric." << std::endl;
	}
	*ctrlD = true;
	return ;
}
