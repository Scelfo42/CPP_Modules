/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:33:22 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/27 16:22:18 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon&		_gun;
		std::string	_name;
	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA( void );

		void	attack( void );
};

#endif