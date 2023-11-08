/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:32:18 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/08 11:54:56 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//========= CONSTRUCTOR =========//

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") { std::cout << "WrongCat default constructor called" << std::endl; }

WrongCat::WrongCat( const WrongCat& sourceClass )
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = sourceClass;
}

//========= DESTRUCTOR =========//

WrongCat::~WrongCat( void ) { std::cout << "WrongCat destructor called" << std::endl; }

//========= OPERATOR ASSIGNMENT OVERLOAD =========//

WrongCat&	WrongCat::operator=( const WrongCat& sourceClass )
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	WrongAnimal::operator=(sourceClass);
	return *this;
}

//========= MEMBER FUNCTION =========//

void	WrongCat::makeSound( void ) const { std::cout << "WrongMeow wrongMeow nigga" << std::endl; }
