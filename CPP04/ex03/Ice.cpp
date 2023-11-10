/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:16:32 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/10 15:59:29 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") { }

Ice::Ice( const Ice& sourceClass ) : AMateria(sourceClass) { this->_type = "ice"; *this = sourceClass; }

Ice::~Ice( void ) { }

Ice&	Ice::operator=( const Ice& sourceClass )
{
	if (this != &sourceClass)
		;
	return *this;
}

AMateria*	Ice::clone( void ) const { return allocTry(ICE); }

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
