/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:20:10 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/30 18:29:34 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
	return ;
}

Harl::~Harl( void )
{
	return ;
}

void	Harl::debug( void )
{
	std::cout << "debug" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "info" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "warning" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "error" << std::endl;
}

void	Harl::complain( std::string level )
{
	void	( Harl::*fun[4] )( ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error }
}
