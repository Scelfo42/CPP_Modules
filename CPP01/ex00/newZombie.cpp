/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:29:19 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/26 14:33:43 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie*	zombie;
	
	try
	{
		zombie = new Zombie(name);
	}
	catch(const std::bad_alloc& error)
	{
		std::cerr << error.what() << std::endl;
	}
	return zombie;
}