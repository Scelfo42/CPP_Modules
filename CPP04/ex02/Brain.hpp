/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:27:44 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/08 12:09:54 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	protected:
		std::string	_ideas[100];
	public:
		Brain( void );
		Brain( const Brain& sourceClass );
		~Brain( void );

		Brain& operator=( const Brain& sourceClass );

		std::string getIdea( int index ) const;
		void		setIdea( int index, std::string idea );
};

#endif