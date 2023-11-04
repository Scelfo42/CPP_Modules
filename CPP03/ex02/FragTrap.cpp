/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:18:47 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 21:21:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//========= CONSTRUCTOR =========//

FragTrap::FragTrap( void ) : ClapTrap() { std::cout << "FragTrap default constructor called" << std::endl; }

FragTrap::FragTrap( const FragTrap& sourceClass )
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = sourceClass;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap parametric constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

//========= DESTRUCTOR =========//

FragTrap::~FragTrap( void ) { std::cout << "FragTrap destructor called" << std::endl; }

//========= OVERLOAD ASSIGNMENT OPERATOR =========//

FragTrap&	FragTrap::operator=( const FragTrap& sourceClass )
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

//========= MEMBER FUNCTION =========//

void	FragTrap::highFivesGuys( void ) { std::cout << "FragTrap " << this->getName() << " says: \"High fives guys!\"" << std::endl; }
