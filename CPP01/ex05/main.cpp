/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:20:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/30 18:52:27 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	level;

	if (argc != 1)
		return 1;
	while (!std::cin.eof())
	{
		std::cout << std::endl << "Please insert a complain level: ";
		std::getline(std::cin, level);
		if (std::cin.eof() || !level.compare(""))
			continue;
		for (size_t i = 0; i < level.length(); i++)
			level[i] = std::toupper(level[i]);
		if (!level.compare("EXIT"))
			break ;
		harl.complain(level);
	}
	(void)argv;
	return 0;
}