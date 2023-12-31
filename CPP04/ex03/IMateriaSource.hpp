/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:59:12 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/09 16:35:02 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <iostream>

class AMateria;

class IMateriaSource
{
	public:
		virtual				~IMateriaSource() {}
		virtual	void		learnMateria( AMateria* ) = 0;
		virtual AMateria*	createMateria( const std::string& type ) = 0;
};

#endif