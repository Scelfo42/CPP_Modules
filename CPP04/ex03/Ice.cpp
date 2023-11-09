/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:16:32 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/09 14:50:48 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") { }

Ice::Ice( const Ice& sourceClass ) : AMateria(sourceClass) { }

Ice::~Ice( void ) { }

Ice&	Ice::operator=( const Ice& sourceClass )
{
	if (this != &sourceClass)
		AMateria::operator=(sourceClass);
	return *this;
}

AMateria*	Ice::clone( void ) const { return allocTry(ICE); }

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
