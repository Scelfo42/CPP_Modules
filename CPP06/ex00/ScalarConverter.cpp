/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:05:17 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/24 14:34:16 by cscelfo          ###   ########.fr       */
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

static void doSpecial( const std::string& input )
{
    std::string special = input;

    std::cout << "char: impossible" << '\n';
    std::cout << "int: impossible" << '\n';
    if (special == "inf" || special == "+inf" || special == "-inf" || special == "nan")
    {
        std::cout << "float: " << special << "f" << '\n';
        std::cout << "double: " << special << std::endl;
    }
    else
    {
        std::cout << "float: " << special << '\n';
        std::cout << "double: " << special.erase(special.length() - 1) << std::endl;
    }
}

static int  selectType( const std::string& input)
{
    size_t  len = input.length();
    size_t  dotFinder = input.find('.');

    if (dotFinder == std::string::npos)
    {
        if (isSpecial(input)) //control if input is special
            return 1;
        else if (isChar(input, len)) //control if input is a char
            return 2;
        else if (isInt(input, len)) //control if input is an int
            return 3;
    }
    else if (len > 0)
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

    try
    {
        switch (type)
        {
            case 0:
                throw ScalarConverter::InputErrorException();
                break ;
            case 1:
                doSpecial(input);
                break ;
            case 2:
                convertChar(input, true);
                break ;
            case 3:
                convertInt(input, true);
                break ;
            case 4:
                convertDouble(input);
                break ;
            case 5:
                convertFloat(input, true);
            default:
                break ;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
