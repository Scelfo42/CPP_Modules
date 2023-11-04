/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:51:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 16:10:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main( void )
{
	FragTrap	frog("Frog");

	frog.attack("a tree");
	frog.takeDamage(5);
	frog.beRepaired(5);
	frog.highFivesGuys();

	return 0;
}
