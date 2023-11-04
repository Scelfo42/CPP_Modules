/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:00:07 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 16:33:23 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() { std::cout << "ScavTrap Default constructor called" << std::endl; }

ScavTrap::ScavTrap( const ScavTrap& sourceClass ) : ClapTrap(sourceClass) 
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = sourceClass;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap Parametric constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap( void ) { std::cout << "ScavTrap destructor called" << std::endl; }

ScavTrap&	ScavTrap::operator=( const ScavTrap& sourceClass )
{
	if (this != &sourceClass)
	{
		this->setName(sourceClass.getName());
		this->setHitPoints(sourceClass.getHitPoints());
		this->setEnergyPoints(sourceClass.getEnergyPoints());
		this->setAttackDamage(sourceClass.getAttackDamage());
	}
	std::cout << "ScavTrap assignation operator called" << std::endl;
	return (*this);
}

void	ScavTrap::attack( const std::string& target )
{
	std::cout << "ScavTrap " << this->getName() << " ";

	if (this->getHitPoints() == 0)
	{
		std::cout << "is not with us anymore, therefore can't attack!" << std::endl;
		return ;
	}
	if (this->getAttackDamage() > 0)
	{
		if (this->getEnergyPoints() == 0)
		{
			std::cout << "is out of energy points and can't attack!" << std::endl;
			return ;
		}
		std::cout << "attacks " << target << ", causing " << this->getAttackDamage() << " points of damage ";
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "and has " << this->getEnergyPoints() << " energy points left!" << std::endl;
		return ;
	}
	std::cout << "attacks " << target << " but misses!" << std::endl;
}

void	ScavTrap::guardGate( void ) { std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode!" << std::endl; }