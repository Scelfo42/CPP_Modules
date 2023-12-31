/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:48:30 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/09 16:41:19 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# define ICE 0
# define CURE 1

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria( void );
		AMateria( const std::string& type );
		AMateria( const AMateria& sourceClass );
		virtual ~AMateria( void );

		AMateria&	operator=( const AMateria& sourceClass );

		const std::string&	getType( void ) const;

		virtual AMateria*	clone( void ) const = 0;
		virtual void		use( ICharacter& target );
};

	AMateria*	allocTry( int which );

#endif