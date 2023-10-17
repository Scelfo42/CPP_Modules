/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:37:04 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/17 15:21:58 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cstdlib>
#include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		Contact( void );
		~Contact( void );

		std::string	checkValue( int field );
		std::string setValue( int field, std::string value );
		std::string	getValue( int field );
};

bool	checkInput( std::string input, int (*funct)(int) );

#endif
