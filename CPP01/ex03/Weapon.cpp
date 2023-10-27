/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:32:37 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/27 15:42:10 by cscelfo          ###   ########.fr       */
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

std::string const & Weapon::getType( void ) const
{
	return this->_type;
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
	return ;
}