/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:32:37 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 21:03:31 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//========= CONSTRUCTOR =========//

Weapon::Weapon( std::string initialType ) : _type(initialType) { }

//========= DESTRUCTOR =========//

Weapon::~Weapon( void ) { }

//========= GETTER FUNCTION =========//

std::string const & Weapon::getType( void ) const { return this->_type; }

//========= SETTER FUNCTION =========//

void	Weapon::setType( std::string type ) { this->_type = type; }