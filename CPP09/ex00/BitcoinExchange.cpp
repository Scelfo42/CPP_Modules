/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:43:09 by cscelfo           #+#    #+#             */
/*   Updated: 2024/01/06 14:41:24 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool isLeapYear( int year )
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

static bool checkDate(std::string key)
{
	std::string	year = key.substr(0, 4);
	std::string	month = key.substr(5, 2);
	std::string	day = key.substr(8, 2);

	int yearInt = std::atoi(year.c_str());
	int monthInt = std::atoi(month.c_str());
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int	dayInt = std::atoi(day.c_str());

	if (yearInt >= 0 && yearInt <= 2024 && monthInt > 0 && monthInt <= 12)
	{
		if (dayInt > 0 && dayInt <= daysInMonth[monthInt - 1])
			return true;
		else
			if (isLeapYear(yearInt) && monthInt == 2 && dayInt == 29)
				return true;
	}
	return false;

}

static bool	checkDbFormat( std::string line, std::string &key )
{
	std::string	keyPart;
	std::string	valuePart;
	int			count = 0;

	if (line.empty() || line.find(',', 0) == std::string::npos)
		return false;
	keyPart = line.substr(0, line.find(',', 0));
	if (keyPart.length() != 10 || keyPart[4] != '-' || keyPart[7] != '-' || !checkDate(keyPart))
		return false;
	valuePart = line.substr(line.find(',', 0) + 1, line.length());

	if (valuePart.length() > 0)
	{
		for (size_t i = 0; i < valuePart.length(); i++)
		{
			if (valuePart[i] < '0' || valuePart[i] > '9')
			{
				if (count++ == 1 || valuePart[i] != '.')
					return false;
			}
		}
		key.assign(keyPart);
		return true;
	}
	return false;
}

static void	setMap( const char *database, std::map<std::string, float> &map )
{
	std::ifstream	db(database);

	if (!db.is_open())
		throw DatabaseMissingException();

	std::string					line;
	std::string					key;

	std::getline(db, line);
	while (std::getline(db, line))
	{
		if (!checkDbFormat(line, key))
			throw DatabaseFormatException();
		map[key] = std::atof(line.substr(line.find(',', 0) + 1, line.length()).c_str());
	}
}

static void	checkInfileFormat( std::string line, std::string &key, float &value )
{
	if (line.empty() || line.find('|', 0) == std::string::npos)
		throw std::runtime_error("Error: bad input => " + line);
	key = line.substr(0, line.find(' ', 0));
	if (key.length() != 10 || key[4] != '-' || key[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ' || !checkDate(key))
		throw std::runtime_error("Error: bad input => " + line);
	for (size_t i = 13; i < line.length(); i++)
	{
		if (line[i] < '0' || line[i] > '9')
		{
			if (line[i] != '.' && line[i] != '-')
				throw std::runtime_error("Error: bad input => " + line);
			else if (line[i] == '-')
				throw InfileValueNotPositiveException();
		}
	}
	value = std::atof(line.substr(13, line.length()).c_str());
	if (value >= 2.14748e+08)
	{
		long int limits = std::atol(line.substr(13, line.length()).c_str());
		if (limits > INT_MAX || limits < 0)
			throw InfileTooLargeException();
	}
}

void	executeMaster( char *inputFile, std::map<std::string, float> &map )
{
	std::ifstream	infile(inputFile);

	if (!infile.is_open())
		throw InfileFailException();
	
	std::string		line;
	std::string		key;
	float			value;
	

	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		try
		{
			checkInfileFormat(line, key, value);
			std::map<std::string, float>::const_iterator occurence = map.lower_bound(key);
			if (occurence == map.end() || occurence->first != key)
			{
				if (occurence == map.begin())\
					throw InfileNoDateFoundException();
				else
					occurence--;
			}
			std::cout << key << " => " << value << " = " << occurence->second * value << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

void	exchange( char *inputFile )
{
	std::map<std::string, float>	map;

	try
	{
		setMap("./database/data.csv", map);
		executeMaster(inputFile, map);
	}
	catch(const std::exception& err)
	{
		std::cerr << err.what() << '\n';
		return ;
	}
}