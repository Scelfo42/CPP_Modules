/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:05:17 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/23 16:43:18 by cscelfo          ###   ########.fr       */
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

static int  selectType( const std::string& input)
{
    size_t  len = input.length();
    size_t  dotFinder = input.find('.');

    if (dotFinder == std::string::npos)
    {
        if (isChar(input, len)) //control if input is a char
            return 1;
        else if (isSpecial(input)) //control if input is special
            return 2;
        else if (isInt(input, len)) //control if input is an int
            return 3;
    }
    else
    {
        if (isDouble(input, len, dotFinder)) //control if input is a double
           return 4;
        else if (isFloat(input, len, dotFinder)) //control if input is a float
            return 5;
    }
    return 0;
}

void    ScalarConverter::convert( const std::string& input )
{
    int type = selectType(input);

    std::cout << "type: " << type << std::endl;
    
    if (type)
    {
        if (type == 2)
            doSpecial(input);
        else
        {
            std::cout << "char: ";
            try
            {
                ScalarConverter::_char = convertChar(input, type);
                std::cout << "'" << ScalarConverter::_char << "'" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
    else
        std::cerr << "Parse error: Wrong input!" << std::endl;
}
