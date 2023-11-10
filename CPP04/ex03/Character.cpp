/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:40:03 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/10 15:58:36 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("default")
{
	for (int i = 0; i < 4; i++)
		this->_materiaSlots[i] = NULL;
}

Character::Character( std::string name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materiaSlots[i] = NULL;
}

Character::Character( const Character& sourceClass ) { *this = sourceClass; }

Character::~Character( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaSlots[i])
			delete this->_materiaSlots[i];
	}
}

Character&	Character::operator=( const Character& sourceClass )
{
	if (this != &sourceClass)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materiaSlots[i])
				delete this->_materiaSlots[i];
			this->_materiaSlots[i] = sourceClass._materiaSlots[i]->clone();
		}
	}
	return *this;
}

const std::string&	Character::getName( void ) const { return this->_name; }

void	Character::equip( AMateria *m )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaSlots[i])
			continue ;
		this->_materiaSlots[i] = m;
		return ;
	}
}

void	Character::unequip( int idx )
{
	if (idx >= 0 && idx <= 3)
		this->_materiaSlots[idx] = NULL;
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx >= 0 && idx <= 3 && this->_materiaSlots[idx])
		this->_materiaSlots[idx]->use(target);
}
