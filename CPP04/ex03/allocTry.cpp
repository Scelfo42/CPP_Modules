/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocTry.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:45:55 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/09 16:37:05 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

AMateria*	allocTry( int which )
{
	if (which == 0)
	{
		try
		{
			return new Ice();
		}
		catch(const std::bad_alloc& err)
		{
		std::cerr << "bad_alloc caught: " << err.what() << '\n';
		}
	}
	else if (which == 1)
	{
		try
		{
			return new Cure();
		}
		catch(const std::bad_alloc& err)
		{
		std::cerr << "bad_alloc caught: " << err.what() << '\n';
		}
	}
	else
		std::cerr << "Unknown materia passed to be allocated..." << std::endl;
	return NULL;
}
