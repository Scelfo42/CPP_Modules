/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:24:34 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/04 21:08:30 by cscelfo          ###   ########.fr       */
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
    std::cout << "I really do!" << std::endl;
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

void    Harl::complain( std::string level )
{
    void        ( Harl::*fun[4] )() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    bool        iscomplaining = false;

    std::cout << std::endl;
    for (int i = 0; i <= 4; i++)
    {
        if (i < 4 && level.compare( levels[i] ))
            continue ;
        switch (i)
        {
            case 0:
                std::cout << "[ DEBUG ]" << std::endl;
                break ;
            case 1:
                std::cout << "[ INFO ]" << std::endl;
                break ;
            case 2:
                std::cout << "[ WARNING ]" << std::endl;
                break ;
            case 3:
                std::cout << "[ ERROR ]" << std::endl;
                break ;
            default:
                if (!iscomplaining)
                    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
                break ;
        }
        if (i < 4)
        {
            (this->*fun[i])();
            iscomplaining = true;
            if (i != 3)
                level.assign(levels[i + 1]);
        }
    }
    std::cout << std::endl;
}
