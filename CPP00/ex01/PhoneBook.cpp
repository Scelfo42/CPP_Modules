/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:35:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/16 17:18:11 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	this->_countContacts = 0;
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
			if (!this->_contacts[this->_countContacts].checkValue(field).compare(""))
			{
				*ctrlD = true;
				break ;
			}
		this->_countContacts++;
	}
}

void	PhoneBook::searchContact( bool* ctrlD )
{
	std::string	contact_info;
	std::string line;
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
			line.assign("           | ");
			contact_info = this->_contacts[i].getValue(j);
			len = contact_info.length();
			if (len <= 10)
				line.replace(10 - len, 10, contact_info);
			else
			{
				line.replace(0, 10, contact_info);
				line.append(".");
			}
			std::cout << line << " | ";
		}
	}
	(void)ctrlD;
}
