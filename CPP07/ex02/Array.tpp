/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:33:31 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/06 16:04:46 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void )
{
	this->_array = new T[0];
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	this->_size = n;
}

template <typename T>
Array<T>::Array( const Array& src )
{
	this->_array = NULL;
	*this = src;
}

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
		if (this->_array)
			delete [] this->_array;
		this->_array = new T[src._size];
		this->_size = src._size;
		for (unsigned int i = 0; i < src._size; i++)
			this->_array[i] = src._array[i];
	}
	return *this;
}

template<typename T>
T&	Array<T>::operator[]( const int index )
{
	if (index < 0 || index > static_cast<int>(this->_size) - 1)
		throw Array::OutOfRangeException();
	return this->_array[index];
}

template <typename T>
unsigned int	Array<T>::size( void ) const { return this->_size; }
