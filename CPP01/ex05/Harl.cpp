/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:20:10 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 21:07:28 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//========= CONSTRUCTOR =========//

Harl::Harl( void ) { }

//========= DESTRUCTOR =========//

Harl::~Harl( void ) { }

//========= MEMBER FUNCTION =========//

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::couy << "I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	void	( Harl::*fun[4] )( ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	elem[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int i = -1;

	while (++i < 4 && level.compare(elem[i]))
		continue;
	if (i < 4)
		(this->*fun[i])( );
	else
		std::cout << "Unknown level of complain" << std::endl;
}
