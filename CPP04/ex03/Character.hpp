/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:57:27 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/09 16:40:56 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria*	_materiaSlots[4];
		std::string	_name;
	public:
		Character( void );
		Character( std::string name );
		Character( const Character& sourceClass );
		~Character( void );

		Character&	operator=( const Character& sourceClass );

		virtual const std::string&	getName( void ) const;
		virtual void				equip( AMateria* m );
		virtual void				unequip( int idx );
		virtual void				use( int idx, ICharacter& target );
};

#endif