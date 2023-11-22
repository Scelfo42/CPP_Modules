/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:05:17 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/22 16:04:00 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char    ScalarConverter::_char = 0;
int     ScalarConverter::_int = 0;
float   ScalarConverter::_float = 0.0f;
double  ScalarConverter::_double = 0.0;

ScalarConverter::ScalarConverter( void ) { }

ScalarConverter::ScalarConverter( const ScalarConverter& srcClass ) { *this = srcClass; }

ScalarConverter::~ScalarConverter( void ) { }

ScalarConverter&    ScalarConverter::operator=( const ScalarConverter& srcClass )
{
    (void)srcClass;
    return *this;
}

static bool inputCheck( std::string input )
{
    if (input.length() < 1)
        return false;
    return true;
}

void    ScalarConverter::convert( std::string input )
{
    if (inputCheck(input))
    {
        std::cout << "char: ";
        try
        {
            ScalarConverter::_char = convertChar(input);
            std::cout << "'" << ScalarConverter::_char << "'" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cerr << "Error: invalid input" << std::endl;
}
