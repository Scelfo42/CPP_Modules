/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isWhat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:29:06 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/23 16:39:48 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool    isChar( const std::string& input, const size_t& len )
{
    return (len == 1 && !isdigit(input[0])) || (len == 3 && input[0] == '\'' && input[2] == '\'');
}

bool    isSpecial( const std::string& input )
{
    return  input == "inf" || input == "+inf" || input == "-inf" ||
            input == "inff" || input == "+inff" || input == "-inff" ||
            input == "nan" || input == "nanf";
}

bool    isInt( const std::string& input, const size_t& len)
{
    size_t  i = 0;
    bool    flag = false;

    if (input[i] == '+' || input[i] == '-')
    {
        i++;
        flag = true;
    }
    for (; i < len; i++)
    {
        if (!isdigit(input[i]) || (!flag && i > 10) || (flag && i > 11))
            return false;
    }
    return true;
}

bool    isDouble( const std::string& input, const size_t& len, const size_t& dotFinder )
{
    for (size_t forward = dotFinder + 1; forward < len; forward++)
    {
        if (!isdigit(input[forward]))
            return false;
    }
    for (int backward = dotFinder - 1; backward >= 0; backward--)
    {
        if (!isdigit(input[backward]) && backward != 0)
            return false;
        if (!isdigit(input[backward]) && backward == 0 && input[backward] != '+' && input[backward] != '-')
            return false;
    }
    return true;
}

bool    isFloat( const std::string& input, const size_t& len, const size_t& dotFinder)
{
    for (size_t forward = dotFinder + 1; forward < len; forward++)
    {
        if (!isdigit(input[forward]) && input[forward] != 'f')
            return false;
        if (input[forward] == 'f' && forward != len - 1)
            return false;
    }
    for (int backward = dotFinder - 1; backward >= 0; backward--)
    {
        if (!isdigit(input[backward]) && backward != 0)
            return false;
        if (!isdigit(input[backward]) && backward == 0 && input[backward] != '+' && input[backward] != '-')
            return false;
    }
    return true;
}
