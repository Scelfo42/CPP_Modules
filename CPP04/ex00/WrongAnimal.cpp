/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:16:26 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/06 14:32:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//========= CONSTRUCTOR =========//

WrongAnimal::WrongAnimal( void ) : _type("wrongDefault") { std::cout << "WrongAnimal default constructor called" << std::endl; }

WrongAnimal::WrongAnimal( std::string type ) : _type(type) { std::cout << "WrongAnimal parametric constructor called" << std::endl; }

WrongAnimal::WrongAnimal( const WrongAnimal& sourceClass )
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = sourceClass;
}

//========= DESTRUCTOR =========//

WrongAnimal::~WrongAnimal( void ) { std::cout << "WrongAnimal destructor called" << std::endl; }

//========= OPERATOR ASSIGNMENT OVERLOAD =========//

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& sourceClass )
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &sourceClass)
		this->setType(sourceClass.getType());
	return *this;
}

//========= GETTER =========//

std::string	WrongAnimal::getType( void ) const { return this->_type; }

//========= SETTER =========//

void	WrongAnimal::setType( std::string type ) { this->_type = type; }

//========= MEMBER FUNCTION =========//

void	WrongAnimal::makeSound( void ) const { std::cout << "Me WrongAnimal! Me make wrongSound but me not know what WrongSound" << std::endl; }
