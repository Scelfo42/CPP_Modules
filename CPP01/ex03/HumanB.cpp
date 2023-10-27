/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:43:21 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/27 17:56:56 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->_name = name;
	this->_gun = NULL;
	return ;
}

HumanB::~HumanB( void )
{
	return ;
}

void	HumanB::attack( void )
{
	std::cout << this->_name;
	if (this->_gun != NULL)
		std::cout << " attacks with " << this->_gun->getType() << std::endl;
	else
		std::cout << " attacks with barehands! WHAT A BRAVE MAN!" << std::endl;
	return ;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->_gun = &weapon;
	return ;
}