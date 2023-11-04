/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:32:38 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 15:52:20 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( const ScavTrap& sourceClass );
		ScavTrap( std::string name );
		~ScavTrap( void );

		ScavTrap&	operator=( const ScavTrap& sourceClass );

		void	attack( const std::string& target );
		void	guardGate( void );
};

#endif