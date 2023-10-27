/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:40:07 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/27 16:16:28 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _gun(weapon)
{
	this->_name = name;
	return ;
}

HumanA::~HumanA( void )
{
	return ;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_gun.getType() << std::endl;
	return ;
}