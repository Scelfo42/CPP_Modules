/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:01:21 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/27 15:55:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef Serializer_HPP
# define Serializer_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	char		character;
	std::string	string;
	int			number;
	float		floatNumber;
	double		doubleNumber;
};

class Serializer
{
    private:
        Serializer( void );
        Serializer( const Serializer& );
        ~Serializer( void );

        Serializer&      operator=( const Serializer& );

    public:
        
        static uintptr_t    serialize( Data* );
        static Data*        deserialize( uintptr_t );
};

#endif