/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:18:33 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/08 12:17:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//========= CONSTRUCTOR =========//

AAnimal::AAnimal( void ) : _type("Default") { std::cout << "AAnimal default constructor called" << std::endl; }

AAnimal::AAnimal( const AAnimal& sourceClass )
{
	std::cout << "AAnimal copy constructor caled" << std::endl;
	*this = sourceClass;
}

AAnimal::AAnimal( std::string type ) : _type(type) { std::cout << "AAnimal parametric constructor called" << std::endl; }

//========= DESTRUCTOR =========//

AAnimal::~AAnimal( void ) { std::cout << "AAnimal Destructor called" << std::endl; }

//========= OPERATOR ASSIGNMENT OVERLOAD =========//

AAnimal&	AAnimal::operator=( const AAnimal& sourceClass )
{
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &sourceClass)
		this->setType(sourceClass.getType());
	return *this;
}

//========= GETTER =========//

std::string	AAnimal::getType( void ) const { return this->_type; }

//========= SETTER =========//

void	AAnimal::setType( std::string type ) { this->_type = type; }
