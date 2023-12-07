/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:35:40 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/07 14:50:30 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <vector>
# include <deque>
# include <typeinfo>

template <typename T>
typename T::iterator	easyfind( T& container, const int& value );

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
