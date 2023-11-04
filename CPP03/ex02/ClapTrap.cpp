/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:20:36 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/03 18:37:41 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("default"), _hitPoints(0), _energyPoints(0), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl; 
}

ClapTrap::ClapTrap( const ClapTrap& sourceClass )
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = sourceClass;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap parametric constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void ) { std::cout << "ClapTrap destructor called" << std::endl; }

ClapTrap&	ClapTrap::operator=( const ClapTrap& sourceClass )
{
	if (this != &sourceClass)
	{
		this->_name = sourceClass.getName();
		this->_hitPoints = sourceClass.getHitPoints();
		this->_energyPoints = sourceClass.getEnergyPoints();
		this->_attackDamage = sourceClass.getAttackDamage();
	}
	return (*this);
}

void	ClapTrap::setName( std::string name ) { this->_name = name; }

void	ClapTrap::setHitPoints( unsigned int hitPoints ) { this->_hitPoints = hitPoints; }

void	ClapTrap::setEnergyPoints( unsigned int energyPoints ) { this->_energyPoints = energyPoints; }

void	ClapTrap::setAttackDamage( unsigned int attackDamage ) { this->_attackDamage = attackDamage; }

std::string	ClapTrap::getName( void ) const { return this->_name; }

unsigned int	ClapTrap::getHitPoints( void ) const { return this->_hitPoints; }

unsigned int	ClapTrap::getEnergyPoints( void ) const { return this->_energyPoints; }

unsigned int	ClapTrap::getAttackDamage( void ) const { return this->_attackDamage; }

void	ClapTrap::attack( const std::string& target )
{
	std::cout << "ClapTrap " << this->getName() << " ";

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


void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap " << this->getName() << " ";
	if (this->getHitPoints() == 0)
	{
		std::cout << "is already dead, therefore can't take anymore damage!" << std::endl;
		return ;
	}
	if (amount > 0)
	{
		std::cout << "takes " << amount << " points of damage! ";
		if (amount >= this->getHitPoints())
		{
			std::cout << "and dies!" << std::endl;
			this->setHitPoints(0);
			return ;
		}
		this->setHitPoints(this->getHitPoints() - amount);
		std::cout << "and has " << this->getHitPoints() << " hit points left!" << std::endl;
		return ;
	}
	std::cout << "is very fast and dodges the attack avoiding damages!" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap " << this->getName() << " ";
	if (amount > 0 && this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "is repaired by " << amount << " points! ";
		this->setHitPoints(this->getHitPoints() + amount);
		std::cout << "and now has: " << this->getHitPoints() << " hit points left and ";
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << this->getEnergyPoints() << " energy points left!" << std::endl;
		return ;
	}
	std::cout << "is unable to repair itself! caused by ";
	if (this->getHitPoints() == 0)
		std::cout << "death!";
	else if (this->getEnergyPoints() == 0)
		std::cout << "lack of energy points!";
	else if (amount <= 0)
		std::cout << "lack of repair points!";
	std::cout << std::endl;
}
