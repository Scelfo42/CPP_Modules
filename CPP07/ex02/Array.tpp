/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:33:31 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/05 12:11:43 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : Array(0) { }

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n + 1];
	this->_size = n;
}

template <typename T>
Array<T>::Array( const Array& src ) { *this = src; }

template <typename T>
Array<T>::~Array( void )
{
	if (this->_array)
		delete [] this->_array;
}

template <typename T>
Array<T>&	Array<T>::operator=( const Array& src )
{
	if (this != &src)
	{
		this->_array = new T[src._size + 1];
		this->_size = src._size;
		for (unsigned int i = 0; i < src._size; i++)
			this->_array[i] = src._array[i];
	}
	return *this;
}

template<typename T>
T&	Array<T>::operator[]( const int index )
{
	if (index < 0 || index > static_cast<int>(this->_size))
	{
		throw Array::OutOfRangeException();
	}
	return this->_array[index];
}

template <typename T>
unsigned int	Array<T>::getSize( void ) const { return this->_size; }
