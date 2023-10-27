/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:01:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/27 18:07:45 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

bool	inputError(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong input arguments. They must be in this order:" << std::endl << "-Executable" << std::endl << "-File to be read" << std::endl << "-First string" << std::endl << "-Second string" << std::endl;
		return true;
	}
	else if (!argv[2] || !argv[3] || !*argv[2] || !*argv[3])
	{
		std::cerr << "A string is apparently missing!" << std::endl;
		return true;
	}

	std::ifstream	inputFile(argv[1]);

	if (!inputFile.good())
	{
		std::cerr << "Input file doesn't exist or is missing of reading permissions!" << std::endl;
		return true;
	}
	return false;
}