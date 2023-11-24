/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:05:41 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/24 15:38:46 by cscelfo          ###   ########.fr       */
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

# define MAX_INT std::numeric_limits<int>::max()
# define MIN_INT std::numeric_limits<int>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_FLOAT -3.40282e+38
# define MAX_DOUBLE std::numeric_limits<double>::max()
# define MIN_DOUBLE -1.79769e+308

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

        class InputErrorException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Input error!";
                }
        };
};

bool    isChar( const std::string&, const size_t& );
bool    isSpecial( const std::string& );
bool    isInt( const std::string&, const size_t& );
bool    isDouble( const std::string&, const size_t&, const size_t& );
bool    isFloat( const std::string&, const size_t&, const size_t& );
void    convertChar( const std::string&, const bool& );
void    convertInt( const std::string&, const bool& );
void    convertFloat( const std::string&, const bool& );
void    convertDouble( const std::string& );

#endif
