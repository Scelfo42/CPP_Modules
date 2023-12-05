/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:07:24 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/05 12:11:25 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <time.h>
# include <exception>

template <typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;
	public:
		Array<T>( void );
		Array<T>( unsigned int );
		Array<T>( const Array& );
		~Array<T>( void );

		Array<T>&	operator=( const Array& );
		T&	operator[]( const int );
		unsigned int getSize( void ) const;

		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index out of range";
				}
		};
};

# include "Array.tpp"

#endif
