/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:32:37 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/26 17:48:08 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string initialType )
{
	this->_type = initialType;
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

std::string const & Weapon::getType( std::string type )
{
	return ;
}

void	Weapon::setType( std::string type )
{
	return ;
}