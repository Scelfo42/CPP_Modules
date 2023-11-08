/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:00:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/08 12:18:38 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal( void );
		AAnimal( const AAnimal& sourceClass );
		AAnimal( std::string type );
		virtual ~AAnimal( void );

		AAnimal&	operator=( const AAnimal& sourceClass );

		virtual void	makeSound( void ) const = 0;

		std::string		getType( void ) const;
		void			setType( std::string type );
};

#endif