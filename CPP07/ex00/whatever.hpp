/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:24:26 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/30 17:54:02 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap( T& a, T& b )
{
	T	c = a;

	a = b;
	b = c;
}

template <typename T>
T	min( T x, T y ) { return (x < y) ? x : y; }

template <typename T>
T	max( T x, T y ) { return (x > y) ? x : y; }

#endif
