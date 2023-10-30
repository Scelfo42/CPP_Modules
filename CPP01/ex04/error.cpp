/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:01:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/30 12:44:42 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

static bool	errorMessage(const char *message)
{
	std::cerr << message << std::endl;
	return true;
}

bool	inputError(int argc, char **argv, std::string& filename)
{
	bool			flag = false;
	std::ifstream	inputFile(argv[1]);

	if (argc != 4)
		flag = errorMessage("Wrong input arguments. They must be in this order:\n-Executable\n-File to be read\n-First string\n-Second string");
	else if (!argv[2] || !argv[3] || !*argv[2] || !*argv[3])
		flag = errorMessage("A string is apparently missing!");
	else if (!inputFile.good())
		flag = errorMessage("Input file doesn't exist or is missing of reading permissions!");
	else
	{
		filename = std::string(argv[1]) + ".replace";
		std::ofstream	outputFile(filename.c_str(), std::ofstream::trunc);
		if (!outputFile.failbit)
			flag = errorMessage("Error while opening the output file!");
		outputFile.close();
	}

	inputFile.close();
	return flag;
}