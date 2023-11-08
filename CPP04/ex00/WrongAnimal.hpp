/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:11:08 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/06 14:16:17 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
 		WrongAnimal( const WrongAnimal& sourceClass );
		virtual ~WrongAnimal( void );

		WrongAnimal&	operator=( const WrongAnimal& sourceClass );

		std::string		getType( void ) const;
		void			setType( std::string type );

		void	makeSound( void ) const;
};

#endif