/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:40:07 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 21:01:11 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//========= CONSTRUCTOR =========//

HumanA::HumanA( std::string name, Weapon& weapon ) : _gun(weapon), _name(name) { }

//========= DESTRUCTOR =========//

HumanA::~HumanA( void ) { }

//========= MEMBER FUNCTION =========//

void	HumanA::attack( void ) { std::cout << this->_name << " attacks with their " << this->_gun.getType() << std::endl; }