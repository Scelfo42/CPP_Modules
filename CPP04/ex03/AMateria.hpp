/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:48:30 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/08 13:51:50 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria
{
	protected:
		...;
	public:
		AMateria( const std::string& type );
		...

		const std::string&	getType( void ) const;

		virtual AMateria*	clone( void ) const = 0;
		virtual void		use( ICharacter& target );
};

#endif