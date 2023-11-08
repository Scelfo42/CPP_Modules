/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:32:11 by cscelfo           #+#    #+#             */
/*   Updated: 2023/11/08 14:05:41 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//========= CONSTRUCTOR =========//

Cat::Cat( void ) : Animal("Cat") { std::cout << "Cat default constructor called" << std::endl; }

Cat::Cat( const Cat& sourceClass ) : Animal(sourceClass) { std::cout << "Cat copy constructor called" << std::endl; }

//========= DESTRUCTOR =========//

Cat::~Cat( void ) { std::cout << "Cat destructor called" << std::endl; }

//========= OPERATOR ASSIGNMENT OVERLOAD =========//

Cat&	Cat::operator=( const Cat& sourceClass )
{
	std::cout << "Cat assignment operator called" << std::endl;
	Animal::operator=(sourceClass);
	return *this;
}

//========= MEMBER FUNCTION =========//

void	Cat::makeSound( void ) const { std::cout << "Meow meow!" << std::endl; }
