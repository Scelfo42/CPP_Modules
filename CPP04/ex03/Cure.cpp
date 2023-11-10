/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:23:21 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/10 15:59:49 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") { }

Cure::Cure( const Cure& sourceClass ) : AMateria(sourceClass) { this->_type = "cure"; *this = sourceClass; }

Cure::~Cure( void ) { }

Cure&	Cure::operator=( const Cure& sourceClass )
{
	if (this != &sourceClass)
		;
	return *this;
}

AMateria*	Cure::clone( void ) const { return allocTry(CURE); }

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
