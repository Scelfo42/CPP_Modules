/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:35:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/18 19:28:51 by cscelfo          ###   ########.fr       */
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
	int	index;

	index = (this->_countContacts < 8) ? this->_countContacts : this->_replaceOldest;
	for (int field = 0; field < 5; field++)
	{
		if (!this->_contacts[index].checkValue(field).compare(""))
		{
			*ctrlD = true;
			break ;
		}
	}
	if (this->_countContacts < 8)
		this->_countContacts++;
	else
		(this->_replaceOldest == this->_countContacts - 1) ? (this->_replaceOldest = 0) : this->_replaceOldest++;
}

bool	PhoneBook::checkInputRange( std::string input, int *index )
{
	*index = std::atoi( input.c_str() );
	if (*index == 0 || *index > 8 || this->_countContacts < *index)
	{
		std::cerr << std::endl << "No contact found at this index" << std::endl;
		return false;
	}
	return true;
}

void	PhoneBook::searchContact( bool* ctrlD )
{
	std::string input;
	int			index;
	
	if (this->_countContacts != 0)
	{
		for (int i = 0; i < this->_countContacts; i++)
			this->_contacts[i].printInfo(i);
		while (!std::cin.eof())
		{
			std::cout << std::endl << "Select a contact index or just write 'no' to move on: ";
			std::getline(std::cin, input);
			if (std::cin.eof())
				continue ;
			else if (!input.compare("no"))
			{
				std::cout << "Ok!" << std::endl;
				return ;
			}
			else if (!checkInput( input, std::isdigit ))
				std::cerr << std::endl << "Index must be numeric." << std::endl;
			else if (checkInputRange( input, &index ))
			{
				this->_contacts[index - 1].indexPrint();
				return ;
			}
			else
			{
				std::cout << "Would you like to select another index? Select 'y' or 'n': ";
				std::getline(std::cin, input);
				if (std::cin.eof() || !input.compare("y"))
					continue;
				else if (!input.compare("n"))
					return ;
				else
				{
					std::cout << "Wrong input, exiting..." << std::endl;
					return ;
				}
			}
		}
		*ctrlD = true;
	}
	else
		std::cout << std::endl << "There isn't any contact saved" << std::endl;
	return ;
}
