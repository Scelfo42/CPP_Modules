/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:37:34 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/13 16:39:06 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main( int argc, char *argv[] )
{
	PhoneBook	bob;
	std::string	prompt;

	if (argc != 1)
	{
		std::cerr << "The arguments must not be anything but the executable" << std::endl;
		return (1);
	}
	std::cout << "Please enter one of these commands: ADD, SEARCH, EXIT" << std::endl;
	while (prompt.compare("EXIT"))
	{
		std::cout << std::endl << "$>";
		std::getline(std::cin, prompt);
		if (!prompt.compare("ADD"))
			bob.addContact();
		else if (!prompt.compare("SEARCH"))
			bob.searchContact();
		else if (!std::cin.eof() && prompt.compare("EXIT"))
			std::cout << std::endl << "Please learn to read." << std::endl;
		else
			break ;
	}
	(void)argv;
	return (0);
}