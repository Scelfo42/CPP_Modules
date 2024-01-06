/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:43:34 by cscelfo           #+#    #+#             */
/*   Updated: 2024/01/05 18:08:07 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <exception>
#include <cstdlib>
#include <limits>

# define INT_MAX std::numeric_limits<int>::max()

class DatabaseMissingException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Error: could not open database.";
		}
};

class DatabaseFormatException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Error: database format is invalid.";
		}
};

class InfileFailException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Error: could not open input file.";
		}
};

class InfileValueNotPositiveException : public std::exception
{
	public:
		virtual const char*	what() const throw()
		{
			return "Error: not a positive number.";
		}
};

class InfileTooLargeException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Error: too large a number.";
		}
};

class InfileNoDateFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Error: date couldn't be found in database.";
		}
};

void	exchange( char *database );

#endif