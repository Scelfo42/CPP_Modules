/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:06:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 20:53:51 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//========= CONSTRUCTOR =========//

Zombie::Zombie( std::string name ) : _name(name) { }

//========= DESTRUCTOR =========//

Zombie::~Zombie( void ) { std::cout << this->_name << ": is out, goodbye!" << std::endl; }

//========= MEMBER FUNCTION =========//

void	Zombie::announce( void ) { std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; }