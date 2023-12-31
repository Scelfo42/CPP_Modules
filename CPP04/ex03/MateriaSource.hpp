/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:02:34 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/09 16:39:23 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materia[4];
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource& sourceClass );
		~MateriaSource( void );

		MateriaSource&	operator=( const MateriaSource& sourceClass );

		virtual	void		learnMateria( AMateria* );
		virtual AMateria*	createMateria( const std::string& type );
};

#endif