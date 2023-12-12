/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:15:11 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/12 15:19:49 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <list>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	public:
		MutantStack( void );
		MutantStack( const MutantStack& src );
		~MutantStack( void );

		MutantStack&	operator=( const MutantStack& src );

		typedef typename std::stack<T, C>::container_type::iterator iterator;
		typedef typename std::stack<T, C>::container_type::const_iterator constIterator;
		typedef typename std::stack<T, C>::container_type::reverse_iterator reverseIterator;
		typedef typename std::stack<T, C>::container_type::const_reverse_iterator constReverseIterator;

		iterator				begin( void );
		iterator				end( void );
		reverseIterator			reverseBegin( void );
		reverseIterator			reverseEnd( void );
		constIterator			constBegin( void ) const;
		constIterator			constEnd( void ) const;
		constReverseIterator	constReverseBegin( void ) const;
		constReverseIterator	constReverseEnd( void ) const;
};

#include "MutantStack.tpp"

#endif