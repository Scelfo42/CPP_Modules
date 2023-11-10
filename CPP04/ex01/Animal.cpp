/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:18:33 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/10 15:47:46 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//========= CONSTRUCTOR =========//

Animal::Animal( void ) : _type("default") { std::cout << "Animal default constructor called" << std::endl; }

Animal::Animal( std::string type ) : _type(type) { std::cout << "Animal parametric constructor called" << std::endl; }

Animal::Animal( const Animal& sourceClass )
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = sourceClass;
}

//========= DESTRUCTOR =========//

Animal::~Animal( void ) { std::cout << "Animal destructor called" << std::endl; }

//========= OPERATOR ASSIGNMENT OVERLOAD =========//

Animal&	Animal::operator=( const Animal& sourceClass )
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &sourceClass)
		;
	return *this;
}

//========= GETTER =========//

std::string	Animal::getType( void ) const { return this->_type; }

//========= SETTER =========//

void	Animal::setType( std::string type ) { this->_type = type; }

//========= MEMBER FUNCTION =========//

void	Animal::makeSound( void ) const { std::cout << "Me animal! Me make sound but me not know what sound" << std::endl; }
