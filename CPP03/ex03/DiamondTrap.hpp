/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:48:08 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 16:08:21 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap( void );
		DiamondTrap( const DiamondTrap& sourceClass );
		DiamondTrap( std::string name );
		~DiamondTrap( void );

		DiamondTrap&	operator=( const DiamondTrap& sourceClass );

		using	ScavTrap::attack;
		
		void	whoAmI( void );
};

#endif