/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:17:17 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/26 16:14:30 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	Zombie*		horde;
	std::string	name;
	std::string	size;
	int			hordeSize;
	int			order = 0;

	(void)argv;
	if (argc > 1)
		return 1;
	while (order != 2)
	{
		if (order == 0)
		{
			std::cout << std::endl << "Enter the size of the horde: ";
			std::getline(std::cin, size);
			hordeSize = atoi(size.c_str());
			if (std::cin.eof())
				return 2;
			else if (hordeSize == 0)
				std::cout << std::endl << "Please insert a valid number." << std::endl;
			else
				order++;
		}
		if (order == 1)
		{
			std::cout << std::endl << "Enter your Zombies' name: ";
			std::getline(std::cin, name);
			if (std::cin.eof())
				return 3;
			else if (!name.compare(""))
				std::cout << std::endl << "Please insert a valid name." << std::endl;
			else
				order++;
		}
	}
	horde = zombieHorde(hordeSize, name);
	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();
	delete[] (horde);
	return 0;
}