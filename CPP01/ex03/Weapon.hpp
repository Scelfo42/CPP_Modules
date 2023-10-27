/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:29:04 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/27 15:41:29 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon( std::string type );
		~Weapon( void );

		std::string const &	getType( void ) const;
		void				setType( std::string type );
};

#endif