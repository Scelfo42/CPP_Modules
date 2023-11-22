/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:31:31 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/22 16:06:38 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool charCheck( std::string input )
{
    if (input.length() > 1 && !std::isdigit(input[0]))
    {
        throw ScalarConverter::ImpossibleException();
        return false;
    }
    else if (std::isdigit(input[0]))
    {
        if (std::atoi(input.c_str()) < 33 || std::atoi(input.c_str()) > 126)
        {
            throw ScalarConverter::NonDisplayableException();
            return false;
        }
        
        for (int i = 0; input[i]; i++)
        {
            if (!std::isdigit(input[i]))
            {
                throw ScalarConverter::ImpossibleException();
                return false;
            }
        }
    }
    return true;
}

char    convertChar( std::string input )
{
    if (charCheck(input))
    {
        if (input.length() == 1)
            return static_cast<char>(input[0]);
        return static_cast<char>(std::atoi(input.c_str()));
    }
    return 0;
}
