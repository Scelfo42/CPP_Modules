/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:37:34 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/18 14:46:18 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main( int argc, char *argv[] )
{
	PhoneBook	bob;
	std::string	prompt;
	bool		ctrlD;

	if (argc != 1)
	{
		std::cerr << "The arguments must not be anything but the executable" << std::endl;
		return (1);
	}
	ctrlD = false;
	std::cout << "Please enter one of these commands: ADD, SEARCH, EXIT" << std::endl;
	while (prompt.compare("EXIT") && ctrlD == false)
	{
		std::cout << std::endl << "$>";
		std::getline(std::cin, prompt);
		if (std::cin.eof())
			ctrlD = true;
		else if (!prompt.compare("ADD"))
			bob.addContact(&ctrlD);
		else if (!prompt.compare("SEARCH"))
			bob.searchContact(&ctrlD);
		else
			if (prompt.compare("EXIT"))
				std::cout << std::endl << "Please learn how to read." << std::endl;
	}
	(void)argv;
	return (0);
}