/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:00:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/09 11:50:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <typeinfo>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal( void );
		Animal( std::string type );
 		Animal( const Animal& sourceClass );
		virtual ~Animal( void );

		Animal&	operator=( const Animal& sourceClass );

		std::string		getType( void ) const;
		void			setType( std::string type );

		virtual void	makeSound( void ) const;
};

#endif