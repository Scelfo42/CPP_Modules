/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:17:22 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/26 16:19:27 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie*	horde;

	try
	{
		horde = new Zombie[N];
	}
	catch(const std::bad_alloc& error)
	{
		std::cerr << "Caught an error: " << error.what() << std::endl;
		std::cerr << "Aborting..." << std::endl;
		exit(1);
	}
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}
