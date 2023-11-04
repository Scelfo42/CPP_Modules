/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:17:18 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 20:52:50 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//========= CONSTRUCTOR =========//

Zombie::Zombie( void ) { }

//========= DESTRUCTOR =========//

Zombie::~Zombie( void ) { std::cout << this->_name << ": I'm out!" << std::endl; }

//========= MEMBER FUNCTION =========//

void	Zombie::announce( void ) { std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void	Zombie::setName( std::string name ) : _name(name) { }
