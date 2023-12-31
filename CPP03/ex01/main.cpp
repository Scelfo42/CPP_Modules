/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 15:36:43 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap	scavTrap("John");
	ScavTrap	copyScavTrap(scavTrap);
	ScavTrap	defaultScavTrap;

	std::cout << std::endl;

	scavTrap.attack("Bob");
	std::cout << std::endl;
	
	scavTrap.setAttackDamage(42);
	scavTrap.attack("Bob");
	std::cout << std::endl;

	scavTrap.takeDamage(5);
	scavTrap.beRepaired(100);
	std::cout << std::endl;
	
	scavTrap.takeDamage(1000);
	std::cout << std::endl;

	scavTrap.beRepaired(100);
	scavTrap.attack("Bob");
	std::cout << std::endl;
	
	scavTrap.guardGate();
	std::cout << std::endl;

	return 0;
}
