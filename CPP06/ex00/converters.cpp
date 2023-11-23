/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:31:31 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/23 15:35:24 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char    convertChar( const std::string& input, const int& type )
{
    size_t  len = input.length();
    int     atoiResult = std::atoi(input.c_str());
    
    if (type == 1 && len == 1)
        return static_cast<char>(input[0]);
    else if (type == 1 && len == 3)
        return static_cast<char>(input[1]);
    else if ((type == 3 || type == 4 || type == 5) && (atoiResult >= 0 && atoiResult <= 127))
    {
        if (atoiResult > 32 && atoiResult < 127)
            return static_cast<char>(atoiResult);
        else
            throw ScalarConverter::NonDisplayableException();
    }
    else
        throw ScalarConverter::ImpossibleException();
    return 0;
}
