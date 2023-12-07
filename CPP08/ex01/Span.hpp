/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:16:01 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/07 18:09:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SPAN_HPP
# define SPAN_HPP

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

		void	addNumber( int number );
		int		shortestSpan( void );
		int		longestSpan( void );

		class ContainerFullException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "The container is full.";
				}
		};
};

#endif