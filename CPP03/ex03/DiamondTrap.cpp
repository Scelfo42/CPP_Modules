/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:47:34 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 16:33:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& sourceClass ) : ClapTrap(sourceClass), ScavTrap(sourceClass), FragTrap(sourceClass)
{
	std::cout << "Diamond copy constructor called" << std::endl;
	*this = sourceClass;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap parametric constructor called" << std::endl;
	this->_name = name;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap( void ) { std::cout << "DiamondTrap destructor called" << std::endl; }

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& sourceClass )
{
	if (this != &sourceClass)
	{
		this->setName(sourceClass.getName());
		this->setHitPoints(sourceClass.getHitPoints());
		this->setEnergyPoints(sourceClass.getEnergyPoints());
		this->setAttackDamage(sourceClass.getAttackDamage());
	}
	return *this;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "I am DiamondTrap " << this->_name << std::endl;
	std::cout << "And my ClapTrap name is " << ClapTrap::getName() << std::endl;
}
