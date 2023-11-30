/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:44:08 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/30 18:14:34 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	iter(T* array, size_t arrayLength, void (*function)( const T& ))
{
	for (size_t i = 0; i < arrayLength; i++)
		function(array[i]);
}

template<typename T>
void	function( const T& tInstance )
{
	std::cout << tInstance << std::endl;
}

#endif
