/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:16:01 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/12 15:16:28 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename C>
MutantStack<T, C>::MutantStack( void ) : std::stack<T, C>() { }

template <typename T, typename C>
MutantStack<T, C>::MutantStack( const MutantStack& src ) : std::stack<T, C>(src) { *this = src; }

template <typename T, typename C>
MutantStack<T, C>::~MutantStack( void ) { }

template <typename T, typename C>
MutantStack<T, C>&	MutantStack<T, C>::operator=( const MutantStack& src )
{
	if (this != &src)
		this->c = src.c;
	return *this;
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::begin( void ) { return this->c.begin(); }

template <typename T, typename C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::end( void ) { return this->c.end(); }

template <typename T, typename C>
typename MutantStack<T, C>::reverseIterator	MutantStack<T, C>::reverseBegin( void ) { return this->c.rbegin(); }

template <typename T, typename C>
typename MutantStack<T, C>::reverseIterator	MutantStack<T, C>::reverseEnd( void ) { return this->c.rend(); }

template <typename T, typename C>
typename MutantStack<T, C>::constIterator	MutantStack<T, C>::constBegin( void ) const { return this->c.cbegin(); }

template <typename T, typename C>
typename MutantStack<T, C>::constIterator	MutantStack<T, C>::constEnd( void ) const { return this->c.cend(); }

template <typename T, typename C>
typename MutantStack<T, C>::constReverseIterator	MutantStack<T, C>::constReverseBegin( void ) const { return this->c.crbegin(); }

template <typename T, typename C>
typename MutantStack<T, C>::constReverseIterator	MutantStack<T, C>::constReverseEnd( void ) const { return this->c.crend(); }
