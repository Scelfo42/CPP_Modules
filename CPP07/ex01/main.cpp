/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:44:44 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/30 18:11:25 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main( void )
{
	int		arrayInt[5] = { 0, 1, 2, 3, 4 };
	char	arrayChar[5] = { 'a', 'b', 'c', 'd', 'e' };
	float	arrayFloat[5] = { 0.1, 0.2, 0.3, 0.4, 0.5 };

	iter(arrayInt, 5, function);
	iter(arrayChar, 5, function);
	iter(arrayFloat, 5, function);

	return (0);
}