/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:35:40 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/13 14:49:55 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <vector>
# include <deque>
# include <exception>
# include <algorithm>

template <typename T>
typename T::const_iterator	easyfind( const T& container, const int& value );

class ValueNotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Value not found in container";
		}
};

#include "easyfind.tpp"

#endif
