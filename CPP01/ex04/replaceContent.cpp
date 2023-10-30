/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceContent.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:38:30 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/30 16:49:23 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

static std::string	replaceString(std::string line, std::string firstString, std::string secondString)
{
	size_t		pos = line.find(firstString);
	std::string	before = line.substr(0, pos);
	std::string	after = line.substr(pos + firstString.length(), line.length() - pos - firstString.length());
	std::string newLine = before + secondString + after;
	return newLine;
}

void	replaceFileContent( std::ifstream& inputFile, std::ofstream& outputFile, char **argv)
{
	std::stringstream	newContent;
	std::string			firstString;
	std::string			secondString;
	std::string			line;

	firstString.assign(argv[2]);
	secondString.assign(argv[3]);
	while (std::getline(inputFile, line, '\n'))
	{
		while (line.find(firstString) != std::string::npos)
			line = replaceString(line, firstString, secondString);
		newContent << line << std::endl;
	}
	outputFile << newContent.str();
}
