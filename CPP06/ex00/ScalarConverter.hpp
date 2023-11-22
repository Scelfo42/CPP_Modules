/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:05:41 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/22 16:02:11 by cscelfo          ###   ########.fr       */
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
        static void convert( std::string );

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

char    convertChar( std::string );

#endif
