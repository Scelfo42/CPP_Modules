/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:24:26 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/31 17:47:06 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( int argc, char **argv )
{
    Harl        harl;
    std::string level;
    
    if (argc != 2)
    {
        std::cout << "Usage: ./harlFilter <complaint level>" << std::endl;
        return 1;
    }
    level = argv[1];
    for (size_t i = 0; i < level.length(); i++)
        level[i] = std::toupper( level[i] );
    harl.complain( level );
    return 0;
}