/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 16:33:48 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap	diamande("Diamande");

	std::cout << std::endl;

	diamande.whoAmI();
	diamande.attack("target");
	diamande.takeDamage(10);
	diamande.beRepaired(10);
	diamande.guardGate();
	diamande.highFivesGuys();
	diamande.whoAmI();

	std::cout << std::endl;

	return 0;
}
