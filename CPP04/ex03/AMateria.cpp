/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:58:18 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/09 14:50:32 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("default") { }

AMateria::AMateria( const std::string& type ) : _type(type) { }

AMateria::AMateria( const AMateria& sourceClass ) {	*this = sourceClass; }

AMateria::~AMateria( void ) { }

AMateria&	AMateria::operator=( const AMateria& sourceClass )
{
	(void)sourceClass;
	return *this;
}

const std::string&	AMateria::getType( void ) const { return this->_type; }

void	AMateria::use( ICharacter& target )
{
	std::cout << "* shoots a Materia bolt at " << target.getName() << " *" << std::endl;
}
