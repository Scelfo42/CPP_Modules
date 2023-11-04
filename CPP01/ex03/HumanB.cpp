/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:43:21 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 21:02:28 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

//========= CONSTRUCTOR =========//

HumanB::HumanB( std::string name ) : _name(name), _gun(NULL) { }

//========= DESTRUCTOR =========//

HumanB::~HumanB( void ) { }

//========= MEMBER FUNCTION =========//

void	HumanB::attack( void )
{
	std::cout << this->_name;
	if (this->_gun != NULL)
		std::cout << " attacks with " << this->_gun->getType() << std::endl;
	else
		std::cout << " attacks with barehands! WHAT A BRAVE MAN!" << std::endl;
	return ;
}

void	HumanB::setWeapon( Weapon& weapon ) : _gun(&weapon) { }
