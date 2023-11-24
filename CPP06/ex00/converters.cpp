/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:31:31 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/24 16:25:35 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    convertChar( const std::string& input, const bool& printFlag )
{
    char    c = 0;
    size_t  len = input.length();

    if (printFlag)
    {
        if (len == 1)
            c = static_cast<char>(input[0]);
        else if (len == 3)
            c = static_cast<char>(input[1]);
        std::cout << "char: '" << c << "'" << '\n';
        std::cout << "int: " << static_cast<int>(c) << '\n';
        std::cout << "float: " << static_cast<float>(c) << ".0f" << '\n';
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    else
    {
        long int    num = std::atol(input.c_str());
        std::cout << "char: ";

        if (num >= 0 && num <= 127)
        {
            if (num > 32 && num < 127)
                std::cout << "'" << static_cast<char>(num) << "'" << '\n';
            else
                throw ScalarConverter::NonDisplayableException();
        }
        else
            throw ScalarConverter::ImpossibleException();
    }
}

void    convertInt( const std::string& input, const bool& printFlag )
{
    long int    longInt = std::atol(input.c_str());

    try
    {
        convertChar(input, false);   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "int: ";
    try
    {
        if (longInt >= MIN_INT && longInt <= MAX_INT)
            std::cout << static_cast<int>(longInt) << '\n';
        else
            throw ScalarConverter::ImpossibleException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (printFlag)
    {
        std::cout << "float: " << static_cast<float>(longInt) << ".0f" << '\n';
        std::cout << "double: " << static_cast<double>(longInt) << ".0" << std::endl;
    }
}

void    convertFloat( const std::string& input, const bool& printFlag )
{
    float   num = std::atof(input.c_str());
    bool    tolerance = num - static_cast<int>(num) < 0.000000000001;

    try
    {
        convertInt(input, false);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "float: ";
    if (num >= MIN_FLOAT && num <= MAX_FLOAT)
        std::cout << static_cast<float>(num) << (tolerance ? ".0f" : "f") << '\n';
    else
        throw ScalarConverter::ImpossibleException();
    if (printFlag)
        std::cout << "double: " << static_cast<double>(num) << (tolerance ? ".0" : "") << std::endl;
}

void    convertDouble( const std::string& input )
{
    double  num = std::atof(input.c_str());
    bool    tolerance = num - static_cast<int>(num) < 0.000000000001;

    try
    {
        convertFloat(input, false);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "double: ";
    if (num >= MIN_DOUBLE && num <= MAX_DOUBLE)
        std::cout << static_cast<double>(num) << (tolerance ? ".0" : "") << std::endl;
    else
        throw ScalarConverter::ImpossibleException();
}
