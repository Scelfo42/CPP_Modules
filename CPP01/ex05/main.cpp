/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:20:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/30 17:55:55 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	level;

	while (!std::cin.eof())
	{
		std::cout << "Please insert a complain level: ";
		std::getline(std::cin, level);
		if (std::cin.eof() || !level.compare(""))
			continue;
		for (int i = 0; i < level.size(); i++)
			level[i] = std::toupper(level[i]);
		if (!level.compare("EXIT"))
			break ;
		harl.complain(level);
	}
	return 0;
}