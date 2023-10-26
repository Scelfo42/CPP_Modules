/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:56:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/26 14:52:20 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	Zombie*		heapZombie;
	std::string	inputZombie;

	if (argc > 1)
		return 1;
	(void)argv;
	while (!std::cin.eof())
	{
		std::cout << std::endl << "Enter your Zombie's name: ";
		std::getline(std::cin, inputZombie);
		if (std::cin.eof())
			return 2;
		else if (!inputZombie.compare(""))
			std::cout << std::endl << "Please insert a valid name." << std::endl;
		else
			break ;
	}
	std::cout << std::endl << "=========stackZombies=========" << std::endl;
	std::cout << "randomChump's zombie -> ";
	randomChump("Bob");
	std::cout << std::endl << "=========heapZombies=========" << std::endl;
	std::cout << "The dynamically allocated zombie -> ";
	heapZombie = newZombie(inputZombie);
	heapZombie->announce();
	delete(heapZombie);
	return 0;
}
