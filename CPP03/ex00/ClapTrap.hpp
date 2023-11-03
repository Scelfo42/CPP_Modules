/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:11:43 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/03 16:20:34 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap
{
	private:
		std::string	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		ClapTrap( void );
		ClapTrap( const ClapTrap& sourceClass );
		ClapTrap( std::string name );
		~ClapTrap( void );

		ClapTrap&	operator=( const ClapTrap& sourceClass );

		void			setName( std::string name );
		void			setHitPoints( unsigned int hitPoints );
		void			setEnergyPoints( unsigned int energyPoints );
		void			setAttackDamage( unsigned int attackDamage );

		std::string		getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getAttackDamage( void ) const;

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif