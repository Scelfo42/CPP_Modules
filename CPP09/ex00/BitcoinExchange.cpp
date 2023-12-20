/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:43:09 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/20 14:58:29 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	checkDbFormat( std::string line, bool *floatValue )
{
	std::string	key;
	std::string	value;

	if (line.empty() || line.find(',', 0) == std::string::npos)
		return false;
	key = line.substr(0, line.find(',', 0));
	value = line.substr(line.find(',', 0) + 1, line.length());
	if (key.length() == 10 && key[4] == '-' && key[7] == '-' && value.length() > 0)
	{
		std::string	subKey[3] = { key.substr(0, 4), key.substr(5, 2), key.substr(8, 2) };
		if (std::atoi(subKey[0].c_str()) > 2023 || std::atoi(subKey[0].c_str()) < 0)
			return false;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < subKey[i].length(); j++)
			{
				if (subKey[i][j] < '0' || subKey[i][j] > '9')
					return false;
			}
		}
		for (int i = 0; i < value.length(); i++)
		{
			if (value[i] < '0' || value[i] > '9')
			{
				if (value[i] == '.' && *floatValue == false)
					*floatValue = true;
				else
					return false;
			}
		}
	}
}

template <typename T>
std::map<std::string, T>	setMap( char *database )
{
	std::ifstream	db(database);

	if (!db.is_open())
		throw DatabaseMissingException();

	std::map<std::string, T>	map;
	std::string					line;
	std::string					key;
	bool						floatValue;

	while (std::getline(database, line))
	{
		if (!checkDbFormat(line, &floatValue))
			throw DatabaseFormatException();
	}
}

template <typename T>
void	exchange( char *inputFile )
{
	std::ifstream				infile(inputFile);
	std::map<std::string, T>	map;

	try
	{
		map = setMap("data.csv");
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << '\n';
		return ;
	}
	
}