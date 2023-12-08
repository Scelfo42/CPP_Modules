/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:16:01 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/08 19:10:25 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SPAN_HPP
# define SPAN_HPP

# define INT_MIN std::numeric_limits<int>::min()
# define INT_MAX std::numeric_limits<int>::max()
# define LONG_MAX std::numeric_limits<long int>::max()

# include <iostream>
# include <limits>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <exception>

class Span
{
	private:
		std::vector<int>	_container;
		unsigned int		_maxSize;
	public:
		Span( void );
		Span( unsigned int n );
		Span( const Span& src );
		~Span( void );

		Span&	operator=( const Span& src );

		void				addNumber( const int& );
		void				addNumber( const long int& );
		void				addNumber( const long int&, const size_t& );
		void				addNumber( const size_t&, std::string );
		long int			shortestSpan( void );
		long int			longestSpan( void );
		std::vector<int>&	getContainer( void );
		const unsigned int&	getMaxSize( void ) const;

		class ContainerFullException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Adding that number would exceed the container's size.";
				}
		};

		class ContainerFewElementsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "The container has too few elements to find a span.";
				}
		};

		class InvalidNumberException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "The number isn't an integer so it can't be added to the container.";
				}
		};
};

#endif