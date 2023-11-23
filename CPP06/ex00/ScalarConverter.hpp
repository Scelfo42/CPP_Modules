/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:05:41 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/23 16:39:01 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <exception>
# include <string>
# include <cstdlib>

class ScalarConverter
{
    private:
        static char    _char;
        static int     _int;
        static float   _float;
        static double  _double;

        ScalarConverter( void );
        ScalarConverter( const ScalarConverter& );
        ~ScalarConverter( void );

        ScalarConverter&    operator=( const ScalarConverter& );
    public:
        static void convert( const std::string& );

        class ImpossibleException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Impossible";
                }
        };

        class NonDisplayableException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Non displayable";
                }
        };
};

bool    isChar( const std::string&, const size_t& );
bool    isSpecial( const std::string& );
bool    isInt( const std::string&, const size_t& );
bool    isDouble( const std::string&, const size_t&, const size_t& );
bool    isFloat( const std::string&, const size_t&, const size_t& );
char    convertChar( const std::string&, const int& );

#endif
