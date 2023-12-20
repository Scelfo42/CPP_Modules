/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:43:34 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/20 11:44:39 by cscelfo          ###   ########.fr       */
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

void	exchange( char *inputFile );

#endif