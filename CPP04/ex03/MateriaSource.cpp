/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:44:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/09 16:52:38 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& sourceClass )
{
	*this = sourceClass;
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& sourceClass )
{
	if (this != &sourceClass)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			this->_materia[i] = sourceClass._materia[i]->clone();
		}
	}
	return *this;
}

void	MateriaSource::learnMateria( AMateria* newMateria )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			continue ;
		this->_materia[i] = newMateria;
		return ;
	}
}

AMateria*	MateriaSource::createMateria( const std::string& type )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && !this->_materia[i]->getType().compare(type))
			return this->_materia[i]->clone();
	}
	return NULL;
}
