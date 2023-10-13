/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:35:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/13 19:13:15 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	std::cout << "PhoneBook constructor called" << std::endl << std::endl;
	return ;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

void	PhoneBook::addContact( void )
{
	if (this->_countContacts < 8)
	{
		for (int field = 0; field < 5; field++)
			this->_contacts[this->_countContacts].checkValue(field);
		this->_countContacts++;
	}
}

void	PhoneBook::searchContact( void )
{
	std::cout << "Searching contact..." << std::endl;
	return ;
}
