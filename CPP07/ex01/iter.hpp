/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:44:08 by cscelfo           #+#    #+#             */
/*   Updated: 2023/12/01 15:57:20 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename N, typename F>
void	iter(T* array, N arrayLength, F function)
{
	for (N i = 0; i < arrayLength; i++)
		function(array[i]);
}

#endif
