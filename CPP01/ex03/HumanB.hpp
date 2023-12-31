/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:39:21 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/27 16:37:42 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*_gun;
		std::string	_name;
	public:
		HumanB( std::string name );
		~HumanB( void );
		
		void	attack( void );
		void	setWeapon( Weapon& weapon );
};

#endif