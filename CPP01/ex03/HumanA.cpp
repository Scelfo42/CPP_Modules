/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:40:07 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/26 17:47:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon weapon )
{
	this->_name = name;
	this->_gun = weapon;
	return ;
}

HumanA::~HumanA( void )
{
	return ;
}

void	HumanA::attack( void )
{
	return ;
}