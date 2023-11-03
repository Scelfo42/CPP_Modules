/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/03 18:36:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	defaultClapTrap;
	ClapTrap	copyClapTrap(defaultClapTrap);
	ClapTrap	clapper("Bob");

	std::cout << std::endl;

	clapper.attack("John");

	std::cout << std::endl;
	
 	clapper.setAttackDamage(42);
	clapper.attack("John");

	std::cout << std::endl;

	clapper.takeDamage(5);
	clapper.beRepaired(100);

	std::cout << std::endl;

	clapper.takeDamage(150);

	std::cout << std::endl;

	clapper.beRepaired(100);
	clapper.attack("John");

	std::cout << std::endl;

	return 0;
}